//  Created by Nathan Perry.
//


/**
 @enum KIFTestStepResult
 @abstract Result codes from a test step.
 @constant KIFTestStepResultFailure The step failed and the test controller should move to the next scenario.
 @constant KIFTestStepResultSuccess The step succeeded and the test controller should move to the next step in the current scenario.
 @constant KIFTestStepResultWait The test isn't ready yet and should be tried again after a short delay.
 */
enum {
    KIFTestStepResultFailure = 0,
    KIFTestStepResultSuccess,
    KIFTestStepResultWait,
};
typedef NSInteger KIFTestStepResult;
