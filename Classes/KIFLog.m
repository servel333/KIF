//  Created by Nathan Perry.
//


#import "KIFLog.h"


float const KIFDefaultStepTimeout = 10.0;


#pragma mark -


@implementation KIFLog


- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


#pragma mark Log messages


- (void)message:(NSString *)message
{
    NSLog(message, @"");
}


@end
