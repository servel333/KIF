//  Created by Nathan Perry.
//


#import "KIFTypes.h"
#import "KIFStepNotifications.h"


/*!
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


/*!
 @typedef KIFTestStepExecutionBlock
 @param step The step object itself. This is passed back to the block to ensure that there is a pointer to the fully initialized step at the time of execution.
 @param error An error to fill out in the case of a failure or wait condition. Filling out this error is mandatory in these cases to ensure that testing output is useful.
 @result A test result code. Returning KIFTestStepResultWait will cause the step to be tried again on the next iteration.
 */
typedef KIFTestStepResult (^KIFTestStepExecutionBlock)(KIFTestStep *step, NSError **error);


@interface KIFTestStepWithExecutionBlock : NSObject <KIFTestStepDelegate> {
    KIFTestStepExecutionBlock executionBlock;
}


@end
