//  Created by Nathan Perry.
//


#import "KIFContext.h"


@protocol KIFStep;


/**
 @class  KIFMutableContext
 @abstract  A version of the KIFContext that includes setters.
 */
@interface KIFMutableContext : KIFContext


#pragma mark Convenience constructors


/**
 @abstract  Creates and returns an empty context.
 */
+ (id)context;


#pragma mark Setters


- (void)setController:(KIFController *)controller;
- (void)setScenario:(KIFScenario *)scenario;
- (void)setStep:(KIFStepProtocol *)step;
- (void)setFirstRunStep:(NSTimeInterval)firstRanStep;
- (void)setLastRunStep:(NSTimeInterval)lastRanStep;


#pragma mark Properties


/**
 @property  controller
 @abstract  The KIF controller.
 */
@property (nonatomic, readwrite, retain) KIFController *controller;


/**
 @property  scenario
 @abstract  The currently executing scenario.
 */
@property (nonatomic, readwrite, retain) KIFScenario *scenario;


/**
 @property  step
 @abstract  The currently executing step.
 */
@property (nonatomic, readwrite, retain) KIFStepProtocol *step;


/**
 @property  firstRanStep
 @abstract  The time interval relative to the reference date when this step was run for the first time.
 */
@property (nonatomic, readwrite, assign) NSTimeInterval firstRanStep;


/**
 @property  firstRanStep
 @abstract  The time interval relative to the reference date when this step was run the most recent time.
 */
@property (nonatomic, readwrite, assign) NSTimeInterval lastRanStep;


@end
