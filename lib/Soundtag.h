//
//  Playground.h
//
//  Created by Sung-ho Song on 2013/05/10
//  Copyright 2013 Perples, Inc All right reserved.
//

#import <Foundation/Foundation.h>


@protocol SoundtagDelegate;


@interface Soundtag: NSObject

// initialize soundtag api
//
// apiKey: key for launching a soundtag API (required)
//
// delegate: asynchronous response delegator (required)
//
// userKey: custom user identifier (optional)
//
//  -> code => 2000: initialize success
//  -> else: initialize failure
+ (void)Init:(NSString *)apiKey with:(id<SoundtagDelegate>)delegate;
+ (void)Init:(NSString *)apiKey with:(id<SoundtagDelegate>)delegate withUserKey:(NSString *)userKey ;


// shutdown soundtag api
+ (void)TearDown;


// asynchronously play the reserved signal
//
// signal: a reserved long integer value that contains message less than 256 bytes
// this signal can be retrieved from the api portal or the http api request(previously chosen fixed ip address)
+ (void)Play:(long long)channel;

// asynchronously catch the signal
+ (void)Listen:(id<SoundtagDelegate>)delegate;


// asynchronously play a instance message. timeout is 60 seconds.
// can be used to deliver the message to many devices
+ (void)Broadcast:(NSString*)message;


// asynchrnously make a transaction for 1-to-1. timeout is 60 seconds.
// you will get notification when the target device received your message.
+ (void)Transaction:(NSString*)message with:(id<SoundtagDelegate>)delegate;


// cancel operation
// it cancels Play, Listen, Background, Transaction function
+ (void)Cancel;

@end


@protocol SoundtagDelegate <NSObject>

@required
- (void)receive:(int)code from:(NSString *)userKey with:(NSString *)context;

@end
