//  Created by Nathan Perry.
//


#import "KIFStepContext.h"


/*!
 @class  KIFMutableStepContext
 @abstract  A version of the KIFStepContext that includes setters.
 */
@interface KIFMutableStepContext : KIFStepContext


- (void)setController:(KIFController *)controller;
- (void)setScenario:(KIFScenario *)scenario;
- (void)setStep:(KIFStep *)step;
- (void)setFirstRunStep:(NSTimeInterval)firstRanStep;
- (void)setLastRunStep:(NSTimeInterval)lastRanStep;


@end
