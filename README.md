
# Record Video Using  <AVFoundation/AVFoundation.h> and <AssetsLibrary/AssetsLibrary.h> for objective-c.

Add following files in your <DEFAULT_CONTROLLER.h> file
#import <AVFoundation/AVFoundation.h>
#import <AssetsLibrary/AssetsLibrary.h>

#define CAPTURE_FRAMES_PER_SECOND		20  // FPS Scale

@interface <YOUR_CONTROLLER.h> : UIViewController
<AVCaptureFileOutputRecordingDelegate>
{
    BOOL WeAreRecording;
    
    AVCaptureSession *CaptureSession;
    AVCaptureMovieFileOutput *MovieFileOutput;
    AVCaptureDeviceInput *VideoInputDevice;
}

@property (retain) AVCaptureVideoPreviewLayer *PreviewLayer;  //Top layer for previewing camera state

- (void) CameraSetOutputProperties;
- (AVCaptureDevice *) CameraWithPosition:(AVCaptureDevicePosition) Position;
- (IBAction)StartStopButtonPressed:(id)sender;
- (IBAction)CameraToggleButtonPressed:(id)sender;

@end

# After that implement these protocols in <YOUR_CONTROLLER.m> file.

Following defines the active code for recording , for initialisation you can download the sample project and refer to  <view did load> methoad and another camera property methods

- (IBAction)StartStopButtonPressed:(id)sender
{
    
    if (!WeAreRecording)
    {
        //----- START RECORDING -----
        NSLog(@"START RECORDING");
        WeAreRecording = YES;
        
        NSString *outputPath = [[NSString alloc] initWithFormat:@"%@%@", NSTemporaryDirectory(), @"output.mov"];
        NSURL *outputURL = [[NSURL alloc] initFileURLWithPath:outputPath];
        
        NSFileManager *fileManager = [NSFileManager defaultManager];
        
        if ([fileManager fileExistsAtPath:outputPath])
        {
            NSError *error;
            if ([fileManager removeItemAtPath:outputPath error:&error] == NO)
            {
                //Error - handle if requried
            }
        }
        //Start recording

        [MovieFileOutput startRecordingToOutputFileURL:outputURL recordingDelegate:self];
    }
    else
    {
        //----- STOP RECORDING -----
        NSLog(@"STOP RECORDING");
        WeAreRecording = NO;
        
        [MovieFileOutput stopRecording];
    }
}
-------
For any unresponsive behaviour , feel free to report an issue.
Thankyou
