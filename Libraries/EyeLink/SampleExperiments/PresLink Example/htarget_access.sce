no_logfile = true;
begin;
begin_pcl;

#
#
#-------------------------UTILITY FUNCTIONS-------
#
#

# utility function returns the target x position.
sub
	int  get_target_x( double compressed_data )
begin
	return int(((compressed_data/65536.0)/65536.0))%65536;	
end;


# utility function returns the target y position.
sub
	int  get_target_y( double compressed_data )
begin			
	return int((compressed_data/65536.0))%65536;	
end;


# utility function returns the target distance.
sub
	int  get_target_distance( double compressed_data )
begin
	return int(compressed_data)%65536;
end;
	
	

int x =0;
int y =0;
#initialize PresLink.
eye_tracker tracker = new eye_tracker( "PresLink" );

#connect to Eyelink tracker.
tracker.start_tracking();

string tracker_ver = tracker.get_parameter("tracker_version");

#tracker_ver would be something like EYELINK CL 4.48, but we want to get the 4.48
array <string> starr[5];
tracker_ver.split(" ",starr);
double tr_v = double(starr[3]);


#open edf file on the tracker.
string edf_name = "track.edf";
if(logfile.subject().count() >0) then
	edf_name = logfile.subject() + "2.edf";
end;
tracker.set_parameter("open_edf_file",edf_name);

#set preamble
tracker.send_command("add_file_preamble_text 'PresLink Example 2'");

#get tracker time
double st = clock.time_double();
string tracker_time_s = tracker.get_parameter("tracker_time");
double en = clock.time_double();
double tracker_time_base = st;
double tracker_time_offset = double(tracker_time_s) + (en-st)/2.0;

term.print("start time =");
term.print(st);
term.print(" end time =");
term.print(en);
term.print(" Tracker Time Access Delay=");
term.print(en-st);
term.print(" Tracker Time =");
term.print(tracker_time_s);

	string msg = "time sync ";
	msg.append(string(st));
	msg.append("/");
	msg.append(string(en));
	msg.append("/");
	msg.append(string(en-st));
	msg.append("/");
	msg.append(tracker_time_s);
	msg.append("/");
	msg.append(string(tracker_time_offset));

tracker.send_message(msg);

term.print("\n");


tracker.set_parameter("file_event_filter", "LEFT,RIGHT,FIXATION,SACCADE,BLINK,MESSAGE,BUTTON");		   
tracker.set_parameter("link_event_filter","LEFT,RIGHT,FIXATION,SACCADE,BLINK,BUTTON");

if (tr_v >=4.0) then
	tracker.set_parameter("link_sample_data" ,"LEFT,RIGHT,GAZE,GAZERES,AREA,STATUS,HTARGET");
	tracker.set_parameter("file_sample_data",  "LEFT,RIGHT,GAZE,AREA,GAZERES,STATUS,HTARGET");
else
	tracker.set_parameter("link_sample_data","LEFT,RIGHT,GAZE,GAZERES,AREA,STATUS"); 
	tracker.set_parameter("file_sample_data",  "LEFT,RIGHT,GAZE,AREA,GAZERES,STATUS");
end;

#program button #5 for use in drift correction
tracker.send_command("button_function 5 'accept_target_fixation'");

#tell the tracker to use 9 point calibration.
tracker.set_parameter("calibration_type","HV9");


#tell PresLink that we need gaze data for both eyes
tracker.start_data( et_left, dt_position, false );
tracker.start_data( et_right, dt_position, false );

#-----------------------CALIBRATION----------------------
#calibrate using a custom target. 
#tell PresLink to use the target.bmp as the target - taken from the user's home directory. 
#If using, camera setup no custom target available.
string target_fname  = stimulus_directory +"target.bmp"; 
tracker.set_parameter("target_file",target_fname); 


#---------------------ENABLE HTARGET DATA------------
#
#
#tell PresLink that we also need pupil data.
tracker.start_data( dt_pupil, false );
tracker.start_data( dt_pupil, false );
#tell Preslink that we want the pupil_data filled with hdata.
tracker.set_parameter("enable_htarget","1");
term.print("Sample Time(rough)\tTime\tdiameter\ttarget_x\ttarget_y\ttarget_distance\n");
tracker.set_recording(true);
loop
	int end_time = clock.time() + 5000
until
	clock.time() >= end_time 
begin
	if(tracker.new_pupil_data() > 0) then
		pupil_data sam = tracker.last_pupil_data();
		double target = sam.y_diameter();
		term.print((double(sam.time())+tracker_time_base)+tracker_time_offset);  term.print("\t"); #this time is very rough and subject to drift
		term.print(sam.time());        term.print("\t");
		term.print(sam.x_diameter());  term.print("\t");
		term.print(get_target_x(target));term.print("\t");
		term.print(get_target_y(target));term.print("\t");
		term.print(get_target_distance(target));term.print("\n");
	
	msg = "sample ";
	msg.append(string((double(sam.time())+tracker_time_base)+tracker_time_offset));
	msg.append("/");
	msg.append(string(sam.time()));
	msg.append("/");
	msg.append(string(sam.x_diameter()));
	msg.append("/");
	msg.append(string(get_target_x(target)));
	msg.append("/");
	msg.append(string(get_target_y(target)));
	msg.append("/");
	msg.append(string(get_target_distance(target)));
	tracker.send_message(msg);
	
		
	end;
	#wait_interval(100);

end;
tracker.set_recording(false);	
	

#transfer the edf file. Note Presentation places files specified without a path in the user's home directory.
#in this example pres_1.edf will be placed in your home directory. (eg. in xp C:\documents and settings\<username>
string edf_fname = logfile_directory + edf_name;
tracker.set_parameter("get_edf_file",edf_fname);
tracker.stop_tracking();