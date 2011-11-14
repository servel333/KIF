//  Created by Nathan Perry.
//


#import <Foundation/Foundation.h>


@class KIFTestController;
@class KIFTestScenario;
@class KIFTestStepDelegate;


#pragma mark -


@interface KIFTestContext : NSObject


/*!
 @property  controller
 @abstract  The 
 */
@property (nonatomic, readonly) KIFTestController *controller;


/*!
 @property  scenario
 @abstract  The currently executing scenario.
 */
@property (nonatomic, readonly) KIFTestScenario *scenario;


/*!
 @property  step
 @abstract  The currently executing step.
 */
@property (nonatomic, readonly) KIFTestStepDelegate *step;


/*!
 @property  runStepAgain
 @abstract  Indicates if the current step will be run again if it succeeds.
 @discussion  This property is set to false (NO) before the step is run.  The step is expected to set it to true (YES) if it needs to be run again.
 
 The steps timeout ends only after it is not flagged to run again.
 */
@property (nonatomic) BOOL runStepAgain;


@property (nonatomic, retain) NSError *error;


@end
