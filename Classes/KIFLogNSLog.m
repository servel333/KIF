//  Created by Nathan Perry.
//


#import "KIFLogNSLog.h"

#import "KIFLog-Protocol.h"


#pragma mark -


@implementation KIFLogNSLog


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
