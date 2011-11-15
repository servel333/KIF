//  Created by Nathan Perry.
//


/*!
 @file
 @abstract  Importing this file will import everything you need to use KIF itself.
 */


#import "KIFController.h"
#import "KIFControllerContext.h"
#import "KIFControllerDelegate.h"
#import "KIFMacros.h"
#import "KIFScenario.h"
#import "KIFStepContext.h"
#import "KIFStepNotifications.h"


/*!
 @typedef KIFTestStepExecutionBlock
 @param step The step object itself. This is passed back to the block to ensure that there is a pointer to the fully initialized step at the time of execution.
 @param error An error to fill out in the case of a failure or wait condition. Filling out this error is mandatory in these cases to ensure that testing output is useful.
 @result A test result code. Returning KIFTestStepResultWait will cause the step to be tried again on the next iteration.
 */
typedef KIFTestStepResult (^KIFTestStepExecutionBlock)(KIFTestStep *step, NSError **error);
