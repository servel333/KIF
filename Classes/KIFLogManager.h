//  Created by Nathan Perry.
//


#import "KIFLogProtocol.h"
#import "KIFSingleton.h"


#pragma mark -


/**
 @abstract  Manages a list of loggers and redirects messages to all attached loggers.
 */
@interface KIFLogManager : NSObject {
    NSArray *_loggers;
}


KIFSingletonInterface(KIFLogManager, sharedManager);


#pragma mark Properties


@property (readonly) NSArray *loggers;


#pragma mark Attach/detach logger


- (void)attachLogger:(KIFLogProtocol *)logger;


- (KIFLogProtocol *)detachLogger:(KIFLogProtocol *)logger;


#pragma mark Message


- (void)message:(NSString *)message;


@end
