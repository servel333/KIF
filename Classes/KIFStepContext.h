//  Created by Nathan Perry.
//


#import <Foundation/Foundation.h>
#import "KIFStepNotifications.h"


@class KIFController;
@class KIFScenario;


#pragma mark -


@interface KIFStepContext : NSObject {
    KIFController *_controller;
    KIFScenario *_scenario;
    NSObject<KIFStepNotifications> *_step;
    NSTimeInterval _firstRanStep;
    NSTimeInterval _lastRanStep;
    BOOL _runStepAgain;
    NSError *_error;
}


#pragma mark Convenience constructors


/*!
 @abstract  Creates and returns an empty context.
 */
+ (id)context;


#pragma mark Properties


/*!
 @property  controller
 @abstract  The KIF controller.
 */
@property (nonatomic, readonly) KIFController *controller;


/*!
 @property  scenario
 @abstract  The currently executing scenario.
 */
@property (nonatomic, readonly) KIFScenario *scenario;


/*!
 @property  step
 @abstract  The currently executing step.
 */
@property (nonatomic, readonly) NSObject<KIFStepNotifications> *step;


/*!
 @property  firstRanStep
 @abstract  The time interval relative to the reference date when this step was run for the first time.
 */
@property (nonatomic, readonly) NSTimeInterval firstRanStep;


/*!
 @property  firstRanStep
 @abstract  The time interval relative to the reference date when this step was run the most recent time.
 */
@property (nonatomic, readonly) NSTimeInterval lastRanStep;


/*!
 @property  runStepAgain
 @abstract  Indicates if the current step will be run again if it succeeds.
 @discussion
 This property is set to false (NO) before the step is run.  The step is expected to set it to true (YES) if it needs to be run again.
 
 The steps timeout ends only after it is not flagged to run again.
 */
@property (nonatomic) BOOL runStepAgain;


/*!
 @property  error
 @abstract  When a step fails, this is read and used in the log message for the step failure.
 */
@property (nonatomic, retain) NSError *error;


@end
