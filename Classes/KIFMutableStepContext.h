//  Created by Nathan Perry.
//


#import "KIFStepContext.h"


/*!
 @class  KIFMutableStepContext
 @abstract  A version of the KIFStepContext that includes setters.
 */
@interface KIFMutableStepContext : KIFStepContext


#pragma mark Convenience constructors


/*!
 @abstract  Creates and returns an empty context.
 */
+ (id)context;


#pragma mark Setters


- (void)setController:(KIFController *)controller;
- (void)setScenario:(KIFScenario *)scenario;
- (void)setStep:(NSObject<KIFStepNotifications> *)step;
- (void)setFirstRunStep:(NSTimeInterval)firstRanStep;
- (void)setLastRunStep:(NSTimeInterval)lastRanStep;


@end
