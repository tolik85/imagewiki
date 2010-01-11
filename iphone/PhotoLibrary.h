/*
 *     Generated by class-dump 3.0.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004 by Steve Nygard.
 */


struct CPRecord;

struct CameraDevice;

struct CameraImageQueueHelper;


struct __CoreSurfaceBuffer;

struct __GSEvent;

struct __GSFont;

typedef struct {
    int _field1;
    int _field2;
    id _field3;
    id _field4;
    float _field5;
    int _field6;
    SEL _field7;
    id _field8;
} CDAnonymousStruct1234;

#import <UIKit/UIKit.h>

@class PLUIController;
@class PLCropOverlay;
@class PLImageTile;
@class PLPhotoLibrary;
@class CameraView;
@class BackgroundView;
@class CameraButtonBar;
@class PhotosNavigationItem;
@class MLPhotoAlbum;
@class DCFFileGroup;
@class MLPhotoAlbum;
@class MLPhoto;
@class CameraController;
@class CameraLoadingView;


@interface CameraController : NSObject
{
    LKLayer *_cameraLayer;
    struct CameraDevice *_camera;
    struct CameraImageQueueHelper *_cameraHelper;
    id _delegate;
    UIView *_previewView;
    BOOL _isPreviewing;
}

+ (id)sharedInstance;
- (id)init;
- (void)_setIsReady;
- (BOOL)isReady;
- (void)_tookPicture:(struct __CoreSurfaceBuffer *)fp8;
- (void)_tookPicture:(struct CGImage *)fp8 jpegData:(struct __CFData *)fp12 imageProperties:(struct __CFDictionary *)fp16;
- (struct CameraImageQueueHelper *)_cameraHelper;
- (BOOL)_setupCamera;
- (void)_tearDownCamera;
- (void)setDelegate:(id)fp8;
- (struct CGRect)_cameraFrame;
- (id)previewView;
- (void)startPreview;
- (void)stopPreview;
- (void)capturePhoto;

@end


@interface CameraLoadingView : UIView
{
    id  _progressIndicator;
}

- (id)initWithFrame:(struct CGRect)fp8;
- (void)startAnimation;
- (void)stopAnimation;
- (void)drawRect:(struct CGRect)fp8;

@end

@interface CameraView : UIView
{
    UIButtonBar *_cameraButtonBar;
    int _availablePictureCount;
    int _captureOrientation;
    BOOL _manipulatingCrop;
    UIView *_fourByThreeBackstop;
    CameraController *_cameraController;
    UIView *_previewView;
    UIView *_animatedCaptureView;
    UIView *_irisView;
    UIView *_staticIrisView;
    int _pictureCapacity;
    BOOL _irisIsClosed;
    PLCropOverlay *_cropOverlay;
    PLImageTile *_imageTile;
    CameraLoadingView *_loadingView;
}

- (void)_playShutterSound;
- (void)_showCropOverlayWithTitle:(id)fp8 subtitle:(id)fp12 OKButtonTitle:(id)fp16 OKButtonColor:(int)fp20 OKButtonShowCamera:(BOOL)fp24 cancelButtonTitle:(id)fp28;
- (void)_updateStatusBar;
- (void)_addAdditionalEXIFPropertiesForCurrentState:(id)fp8 date:(id)fp12 toDictionary:(id)fp16;
- (int)_sensorOrientationForDeviceOrientation:(int)fp8;
- (void)setIsLoading:(BOOL)fp8;
- (void)cameraControllerReadyStateChanged:(id)fp8;
- (void)cameraController:(id)fp8 tookPicture:(id)fp12 withPreview:(id)fp16 jpegData:(struct __CFData *)fp20 imageProperties:(id)fp24;
- (void)setupAnimateCameraPreviewDown:(id)fp8;
- (void)animateCameraPreviewDown;
- (void)_storePictureAnimation:(id)fp8 finished:(id)fp12;
- (id)initWithFrame:(struct CGRect)fp8;
- (void)dealloc;
- (BOOL)shouldShowIris;
- (void)setCameraButtonBar:(id)fp8;
- (id)buttonBar;
- (void)takePictureOpenIrisAnimationFinished;
- (void)takePictureCloseIrisAnimationFinished;
- (void)cameraShutterClicked:(id)fp8;
- (void)viewWillBeDisplayed;
- (void)viewWasDisplayed;
- (void)viewWillBeRemoved;
- (void)cropOverlayWasCancelled:(id)fp8;
- (void)cropOverlayWasOKed:(id)fp8;
- (void)_backgroundSavePhoto;
- (void)_savePhotoFinished:(id)fp8;
- (void)willStartGesture:(int)fp8 inView:(id)fp12 forEvent:(struct __GSEvent *)fp16;
- (void)tearDownIris;
- (void)primeStaticClosedIris;
- (void)showStaticClosedIris;
- (void)hideStaticClosedIris;
- (BOOL)irisIsClosed;
- (void)closeIris:(BOOL)fp8 didFinishSelector:(SEL)fp12;
- (void)openIrisWithDidFinishSelector:(SEL)fp8;
- (void)closeOpenIris;
- (void)openIrisAnimationFinished;
- (void)closeIrisAnimationFinished;
- (void)closeOpenIrisAnimationFinished;

@end
