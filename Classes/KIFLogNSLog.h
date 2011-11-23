//  Created by Nathan Perry.
//


@protocol KIFLog;


#pragma mark -


@interface KIFLogNSLog : NSObject <KIFLog>


#pragma mark Log messages


- (void)message:(NSString *)message;


@end
