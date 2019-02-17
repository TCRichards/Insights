no_logfile = true;
begin;
	
picture {
   background_color = 153,153,153;
} et_calibration;


#stimulus display graphics. 
array {
   bitmap { filename = "dixie.jpg"; preload = false; scale_factor = 2.0; };
   bitmap { filename = "town.jpg"; preload = false; scale_factor = 2.0; };
} graphics;


#cursor for left eye
ellipse_graphic { ellipse_height = 50; ellipse_width = 50; color = 0,255,0; } left_cursor;
      
#cursor for right eye
ellipse_graphic { ellipse_height = 50; ellipse_width = 50; color = 0,0,255; } right_cursor;
		
		
trial {       
   picture {  
      # placeholder - set by PCL
      box { height = 1; width = 1; color = 0,0,0; };
      x = 0; y = 0;  
   } pic1;
} trial1;


begin_pcl;


# utility function returns the last button  press
sub
	int  get_last_button_press_id(string buttonstr )
begin
	if buttonstr.count() >0 then
		array <string> starr[2];
		buttonstr.split(" ",starr);
		return int(starr[1]);	
	end;
		return 0;
end;


int dheight = display_device.height();
int dwidth  = display_device.width();

int x =0;
int y =0;
#initialize PresLink.
eye_tracker tracker = new eye_tracker( "PresLink" );


#tracker.set_parameter("tracker_address", "");         # running as dummy mode
#connect to Eyelink tracker.
tracker.start_tracking();

#tracker.set_parameter("dc_err_sound", "on");          #turn on/off drift correction error sound

string tracker_ver = tracker.get_parameter("tracker_version");

#tracker_ver would be something like EYELINK CL 4.48, but we want to get the 4.48
array <string> starr[5];
tracker_ver.split(" ",starr);
double tr_v = double(starr[3]);


#open edf file on the tracker.
string edf_name = "track.edf";
if(logfile.subject().count() >0) then
	edf_name = logfile.subject() + ".edf";
end;
tracker.set_parameter("open_edf_file",edf_name);

#set preamble
tracker.send_command("add_file_preamble_text 'PresLink Example 1'");

string msg_res = "0 0 ";
	msg_res.append(string(dwidth-1));
	msg_res.append(" ");
	msg_res.append(string(dheight-1));

string msg_coord = "DISPLAY_COORDS 0 0 ";
		msg_coord.append(string(dwidth-1));
		msg_coord.append(" ");
		msg_coord.append(string(dheight-1));
		

tracker.set_parameter("screen_pixel_coords", msg_res);
tracker.send_message(msg_coord); 

tracker.set_parameter("file_event_filter", "LEFT,RIGHT,FIXATION,SACCADE,BLINK,MESSAGE,BUTTON,INPUT");		   
tracker.set_parameter("link_event_filter","LEFT,RIGHT,FIXATION,SACCADE,BLINK,BUTTON,INPUT");

if (tr_v >=4.0) then
	tracker.set_parameter("link_sample_data" ,"LEFT,RIGHT,GAZE,GAZERES,AREA,STATUS,HTARGET,INPUT");
	tracker.set_parameter("file_sample_data",  "LEFT,RIGHT,GAZE,AREA,GAZERES,STATUS,HTARGET,INPUT");
else
	tracker.set_parameter("link_sample_data","LEFT,RIGHT,GAZE,GAZERES,AREA,STATUS,INPUT"); 
	tracker.set_parameter("file_sample_data",  "LEFT,RIGHT,GAZE,AREA,GAZERES,STATUS,INPUT");
end;

#program button #5 for use in drift correction
tracker.send_command("button_function 5 'accept_target_fixation'");

#tell the tracker to use 9 point calibration.
tracker.set_parameter("calibration_type","HV9");




#tell PresLink that we need gaze data for both eyes (if available)
tracker.start_data( et_left, dt_position, false );
tracker.start_data( et_right, dt_position, false );

loop
   int i = 1
until
   i > graphics.count()
begin
	#-----------------------CALIBRATION----------------------	
	# 
	#tell PresLink to use the target.bmp as the target - taken from stimulus_directory. 
	#otherwise the default crosshairs target will be displayed.
	#string target_fname  = stimulus_directory +"target.bmp"; 
	#tracker.set_parameter("target_file",target_fname); 

	#clear out the default calibration target so that we don't get data from previous drawing.
	et_calibration.set_background_color(153,153,153);
	et_calibration.clear(); 
	et_calibration.present();
	

	#start calibration with camera support
	tracker.calibrate( et_calibrate_default, 1.0, 0.0, 0.0 );

	#drift correct at (0,0) with the options to allow Camera Setup and to draw a target
	tracker.calibrate( et_calibrate_drift_correct, 7.0, 0.0, 0.0 );
	
	#load the image.
	graphics[i].set_load_size(double(display_device.height()),double(display_device.width()),0.0);
	graphics[i].load();
	pic1.clear(); #remove all
	pic1.add_part(graphics[i],0,0); 
	
	#
	#Send viewer integration messages and tracker commands to monitor recording.
	#
	tracker.send_command("clear_screen 0");

	# This supplies the title at the bottom of the eyetracker display
	string msg = "record_status_message 'TRIAL ";
	msg.append(string(i));
	msg.append("/");
	msg.append(string(graphics.count()));
	msg.append("'");
	tracker.send_command(msg);

	# Always send a TRIALID message before starting to record.
	# It should contain trial condition data required for analysis.
	msg= "TRIALID TRIAL ";
	msg.append(string(i));
	tracker.send_message(msg);

	# TRIAL_VAR message is recorded for EyeLink Data Viewer analysis
	# It specifies the list of trial variables value for the trial
	# This must be specified within the scope of an individual trial (i.e., after
	# "TRIALID" and before "TRIAL_RESULT")
	msg = "!V TRIAL_VAR TRIAL_IMAGE ";
	msg.append(graphics[i].filename());
	tracker.send_message(msg);


	# IMGLOAD command is recorded for EyeLink Data Viewer analysis
	# It displays a default image on the overlay mode of the trial viewer screen.
	# Writes the image filename + path info
	msg = "!V IMGLOAD FILL ";
	msg.append(graphics[i].filename());
	tracker.send_message(msg);

	#image transfer to EyeLink screen:
	#image format can be 24bit bmp, jpg, or gif.
	tracker.set_parameter("transfer_image",graphics[i].filename());       
	
	#set the the tracker to idle mode.
	tracker.send_command("set_idle_mode");
	#give some time for the tracker to switch mode.
	wait_interval(50);
   
   #start recording
	tracker.set_recording(true);

	#present the stimulus
   trial1.present();  
   #mark the time we presented the stimulus
	tracker.send_message("SYNCTIME"); 
   	
	#get the available eye.
	int eye_av = int(tracker.get_parameter("eye_available"));
	int left_index = 2;
	int right_index = 3;
	if(eye_av == 0) then
		pic1.add_part(left_cursor,0,0);
		left_index = 2;
		right_index = -1;
	elseif(eye_av == 1) then
		pic1.add_part(right_cursor,0,0);
		right_index = 2;
		left_index = -1;
	else
		pic1.add_part(left_cursor,0,0);
		pic1.add_part(right_cursor,0,0);
	end;
		
		
	bool button_pressed = false;
	loop
		int end_time = clock.time() + 25000
	until
		clock.time() >= end_time || button_pressed
	begin
		
		int modified = 0;
		#check for new button presses
		button_pressed =  get_last_button_press_id(tracker.get_parameter("last_button_press"))!=0;
		
		if ((eye_av == 0 || eye_av == 2)) then
			#we have left data OR both eye data
			if(tracker.new_position_data(et_left) >0) then
				eye_position_data epd = tracker.last_position_data(et_left);
				pic1.set_part_x( left_index, epd.x());
				pic1.set_part_y( left_index, epd.y());
				modified = 1;
			end;
		end;	
		
		if ((eye_av == 1 || eye_av == 2)) then
			#we have right data OR both eye data
			if(tracker.new_position_data(et_right) >0) then
				eye_position_data epd = tracker.last_position_data(et_right);
				pic1.set_part_x( right_index, epd.x());
				pic1.set_part_y( right_index, epd.y());
				modified = 1;
			end;
		end;
		if(modified == 1) then
			trial1.present();   
		end;
		modified = 0;
	end;
	
	pic1.clear();
	pic1.set_background_color(153,153,153);
	pic1.present();
	wait_interval(100);
	#stop recording.
	tracker.set_recording(false);
	
	msg= "TRIAL_RESULT ";
	msg.append(string(0));
	tracker.send_message(msg);
	
	graphics[i].unload(); 
   i = i + 1
end;

#close file before transfer is required
tracker.send_command("set_idle_mode"); 
wait_interval(500); 
tracker.set_parameter("close_data_file", "");
wait_interval(100);

#transfer the edf file. Note Presentation places files specified without a path in the user's home directory.
#in this example pres_1.edf will be placed in your home directory. (eg. in xp C:\documents and settings\<username>
string edf_fname = logfile_directory + edf_name;
tracker.set_parameter("get_edf_file",edf_fname);
tracker.stop_tracking();