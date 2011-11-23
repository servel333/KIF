//  Created by Nathan Perry.
//


#import "KIFLogManager.h"


#pragma mark -


@implementation KIFLogManager


- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


KIFSingletonImplementation(KIFLogManager, sharedManager);


#pragma mark Properties


@synthesize loggers = _loggers;


#pragma mark Attach/detach logger


- (void)attachLogger:(KIFLogProtocol *)logger
{
    
}


- (KIFLogProtocol *)detachLogger:(KIFLogProtocol *)logger
{
    
}


#pragma mark Message


- (void)message:(NSString *)message
{
    
}


@end
