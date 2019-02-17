                                                                     
                                                                     
                                                                     
                                             
Three versions of E-Prime example projects are included in this folder:

E-prime 1 folder:
-- This version is intended for use with E-Prime 1.x


E-prime 2 NoCameraImg folder: 
-- This version is intended for use with E-Prime 2 and does not allow the camera image to be transferred to the Display PC monitor prior to calibration.
--Known issues in NoCameraImg example projects:
Calibration sounds may cause projects to crash with error "could not communicate with the thread that fills the sound buffer". If this issue occurs, disable audio feedback during calibration by commenting out the following lines in the user script:

'Enable the following block if you need audio feedback
'In Vista with E-Prime 2, this causes problem.
	Dim AuditoryStimulusSoundBuffer As SoundBuffer
	Set AuditoryStimulusSoundBuffer = AuditoryStimulus.Buffers(1)
	If job = 7 Or job = 8 Then
		AuditoryStimulusSoundBuffer.Filename = "type.wav"
	ElseIf job = 14 Or job = 15 Then
		AuditoryStimulusSoundBuffer.Filename = "qbeep.wav"
	ElseIf job = 18 Or job=19 Then	
		AuditoryStimulusSoundBuffer.Filename ="error.wav"
	End If
		AuditoryStimulusSoundBuffer.Load
		AuditoryStimulusSoundBuffer.Play	'play 



E-prime 2 WithCameraImg folder:
-- This version is intended for use with E-Prime 2. In these examples the camera image can be transferred to the Display PC monitor prior to calibration.
-- Known issues in WithCameraImg example projects:
   1) The camera image display is done by suspending and resuming the E-Prime graphics. This means the screen will flash upon entering and exiting camera setup mode. However, the project should resume normally after this. 
   2) The Windows screen resolution should be set to the same as the screen resolution of the E-Prime project. The SR Research supplied example projects all use a screen resolution of 800x600.

