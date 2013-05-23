Soundtag API iOS
================

SoundTAG API

Getting Start
=============
1. Add a libapi.a Soundtag.h to your xcode project.
1. Ensure that add linking binary with library to your project which is libapi.a CFNetwork.framework, AudioToolbox.framework, AVFoundation.framework, libstdc++.dylib

Notes
=====

1. Please submit comments and questions to support@perples.com

Examples
========

delegate
--------
```Objective-C
// in application delegate header file
#import "Soundtag.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate, SoundtagDelegate>
@end

// in controller header file
#import "Soundtag.h"

@inferface ViewController : UIViewController<SoundtagDelegate>
@end
```

initialize
----------
```Objective-C
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  // Override point for customization after application launch.
  [Soundtag Init:@"api key" with:self withUserKey:@"ios mobile user identifier"];
  return YES;
}

- (void)receive:(int)code from:(NSString *)userKey with:(NSString *)context
{
  if (code == 2000) {
    NSLog(@"initialize success");
  } else {
    NSLog(@"initialize failure");
  }
}
```

transaction
-----------
```Objective-C
- (IBAction)transaction:(id)sender
{
  [Soundtag Transaction:@"Transaction Message" with:self];
}

- (IBAction)cancel:(id)sender
{
  [Soundtag Cancel];
}

- (void) receive:(int)code from:(NSString *)userKey with:(NSString *)context
{
  NSLog(@"%d: %@(%@)", code, context, userKey);
}
```

listen
------
```Objective-C
- (IBAction)listen:(id)sender
{
  [Soundtag Listen:self];
}

- (IBAction)cancel:(id)sender
{
  [Soundtag Cancel];
}

- (void) receive:(int)code from:(NSString *)userKey with:(NSString *)context
{
  NSLog(@"%d: %@(%@)", code, context, userKey);
}
```
