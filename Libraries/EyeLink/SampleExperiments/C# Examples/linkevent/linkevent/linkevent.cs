
using System;

namespace linkevent
{
    public class GetCurrentEyeMovementType
    {
        [STAThread]

        static void Main(string[] args)
        {
            try
            {
                SREYELINKLib.EL_EYE eye = SREYELINKLib.EL_EYE.EL_EYE_NONE;
                double st;
                SREYELINKLib.EyeLinkUtil elutil = new SREYELINKLib.EyeLinkUtil();
                SREYELINKLib.EyeLink el = new SREYELINKLib.EyeLink();
                                              
                el.open("100.1.1.1", 0);
              
                el.sendCommand("file_event_filter = LEFT,RIGHT,FIXATION,SACCADE,BLINK,MESSAGE,BUTTON,INPUT");
                el.sendCommand("file_sample_data = LEFT,RIGHT,GAZE,AREA,GAZERES,STATUS,INPUT");
                el.sendCommand("link_event_filter = LEFT,RIGHT,FIXATION,SACCADE,BLINK,BUTTON,INPUT");
                el.sendCommand("link_sample_data = LEFT,RIGHT,GAZE,GAZERES,AREA,STATUS,INPUT");


                el.setOfflineMode();
                elutil.pumpDelay(50);

                el.startRecording(true, true, true, true);
                el.waitForBlockStart(500, true, true);

                eye = (SREYELINKLib.EL_EYE)el.eyeAvailable();
                if (eye == SREYELINKLib.EL_EYE.EL_BINOCULAR)
                    eye = SREYELINKLib.EL_EYE.EL_LEFT;

                st = elutil.currentTime();
                while ((st + 20000) > elutil.currentTime())
                {
                    SREYELINKLib.IELData elData;
                    SREYELINKLib.IStartSaccadeEvent stsaccevent;
                    SREYELINKLib.IEndSaccadeEvent ensaccevent;
                    SREYELINKLib.IEyeEvent eevent;
                    SREYELINKLib.IStartFixationEvent stfixevent;
                    SREYELINKLib.IEndFixationEvent enfixevent;
                    SREYELINKLib.IFixUpdateEvent fixupdate;


                    elData = el.getNextData();

                    if (elData != null)
                    {
                        switch (elData.eltype)
                        {
                            case SREYELINKLib.EL_DATA_TYPE.EL_SAMPLE_TYPE:
                                // Console.Write("sample: ");
                                // Console.Write(elData.time);
                                // Console.WriteLine("");
                                break;
                            case SREYELINKLib.EL_DATA_TYPE.EL_STARTSACC:
                                stsaccevent = (SREYELINKLib.IStartSaccadeEvent)elData;
                                eevent = (SREYELINKLib.IEyeEvent)elData;
                                if (eevent.eye == eye)
                                {
                                    Console.Write("start saccade: time= ");
                                    Console.Write(elData.time);
                                    Console.WriteLine("");
                                }
                                break;
                            case SREYELINKLib.EL_DATA_TYPE.EL_ENDSACC:
                                stsaccevent = (SREYELINKLib.IStartSaccadeEvent)elData;
                                ensaccevent = (SREYELINKLib.IEndSaccadeEvent)elData;
                                eevent = (SREYELINKLib.IEyeEvent)elData;
                                if (eevent.eye == eye)
                                {
                                    Console.Write("end saccade:  start time= ");
                                    Console.Write(eevent.sttime);
                                    Console.Write(" end time= ");
                                    Console.Write(ensaccevent.entime);
                                    Console.Write("\t");
                                    Console.Write("sgx = ");
                                    Console.Write(stsaccevent.gstx);
                                    Console.Write(" sgy = ");
                                    Console.Write(stsaccevent.gsty);
                                    Console.Write("\t");
                                    Console.Write("endgx = ");
                                    Console.Write(ensaccevent.genx);
                                    Console.Write(" endgy = ");
                                    Console.Write(ensaccevent.geny);
                                    Console.WriteLine("");
                                }
                                break;
                            case SREYELINKLib.EL_DATA_TYPE.EL_STARTFIX:
                                stfixevent = (SREYELINKLib.IStartFixationEvent)elData;
                                eevent = (SREYELINKLib.IEyeEvent)elData;
                                if (eevent.eye == eye)
                                {
                                    Console.Write("start fixation: time= ");
                                    Console.Write(elData.time);
                                    Console.WriteLine("");
                                }
                                break;
                            case SREYELINKLib.EL_DATA_TYPE.EL_ENDFIX:
                                enfixevent = (SREYELINKLib.IEndFixationEvent)elData;
                                eevent = (SREYELINKLib.IEyeEvent)elData;
                                if (eevent.eye == eye)
                                {
                                    Console.Write("end fixation: start time= ");
                                    Console.Write(eevent.sttime);
                                    Console.Write(" end time= ");
                                    Console.Write(enfixevent.entime);
                                    Console.Write("\t");
                                    Console.Write("gx = ");
                                    Console.Write(enfixevent.gavx);
                                    Console.Write(" gy = ");
                                    Console.Write(enfixevent.gavy);
                                    Console.WriteLine("");
                                }
                                break;
                            case SREYELINKLib.EL_DATA_TYPE.EL_FIXUPDATE:
                                fixupdate = (SREYELINKLib.IFixUpdateEvent)elData;
                                eevent = (SREYELINKLib.IEyeEvent)elData;
                                if (eevent.eye == eye)
                                {
                                    Console.Write("end fixation: start time= ");
                                    Console.Write(eevent.time);
                                    Console.Write(" end time= ");
                                    Console.Write(fixupdate.entime);
                                    Console.Write("\t");
                                    Console.Write("gx = ");
                                    Console.Write(fixupdate.gavx);
                                    Console.Write(" gy = ");
                                    Console.Write(fixupdate.gavy);
                                    Console.WriteLine("");
                                }
                                break;
                        }
                    }
                }
                el.stopRecording();
                el.close();

                el = null;
                elutil = null;
            }
            catch (Exception)
            {
                throw;
            }
        }

    }
}
