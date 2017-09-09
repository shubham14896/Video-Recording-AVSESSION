//
//  ViewController.h
//  videoSession
//
//  Created by Shubham Gupta on 9/7/17.
//  Copyright © 2017 Shubham Gupta. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <AVFoundation/AVFoundation.h>
#import <AssetsLibrary/AssetsLibrary.h>
///<Can delete if not storing videos to the photo library.  Delete the assetslibrary framework too requires this)

#define CAPTURE_FRAMES_PER_SECOND		20

@interface MyViewController_iPhone : UIViewController
<AVCaptureFileOutputRecordingDelegate>
{
    BOOL WeAreRecording;
    
    AVCaptureSession *CaptureSession;
    AVCaptureMovieFileOutput *MovieFileOutput;
    AVCaptureDeviceInput *VideoInputDevice;
}

@property (retain) AVCaptureVideoPreviewLayer *PreviewLayer;

- (void) CameraSetOutputProperties;
- (AVCaptureDevice *) CameraWithPosition:(AVCaptureDevicePosition) Position;
- (IBAction)StartStopButtonPressed:(id)sender;
- (IBAction)CameraToggleButtonPressed:(id)sender;

@end

@interface ViewController : UIViewController


@end

