//  Created by Nathan Perry
//


#import <Foundation/Foundation.h>
#import "KIFTypes.h"


@class KIFTestContext;


/*!
 @protocol  KIFTestStepDelegate
 @abstract  Delegate for a step.
 @discussion  This is the step delegate used to execute steps.  Each step has a sequence of functions that are executed in the following order: shouldRunStep, stepWillBegin, runStep and stepWillTerminate.  Any function that returns false (NO) will cancel the remaining function calls except for stepWillTerminate.  stepWillTerminate is always called before the next step is run.
 */
@protocol KIFTestStepDelegate


@optional


#pragma mark Sequence


/*!
 @method  shouldRunStep
 @abstract  Gets a value indicating if this step should be run.
 @discussion  When implemented, used to test if the step should be run; otherwise the stpe is run.  This is called first.  The step is considered successful even if shouldRunStep returns false (NO).
 */
- (BOOL)shouldRunStep:(KIFTestContext *)context;


/*!
 @method  stepWillBegin
 @abstract  Performs any needed step preperation.
 @discussion  When implemented, may be used to perform pre-step 
 */
- (BOOL)stepWillBegin:(KIFTestContext *)context;


/*!
 @method  runStep
 @abstract  Runs this step.
 @result  Returns a value indicating the success of this step.
 @discussion  
 */
- (BOOL)runStep:(KIFTestContext *)context;


/*!
 @method  stepDidEnd
 @abstract  Performs any needed step cleanup.
 @discussion  When implemented, may be used to perform post-step cleanup.  Always run even if shouldRunStep
 */
- (void)stepWillTerminate:(KIFTestContext *)context;


#pragma mark Step descriptors


/*!
 @method  stepDescription
 @abstract  Gets the description of this step.
 @discussion  When implemented and returns a valid value, used in the log message for this step.  Otherwise, the default message will be used.
 */
- (NSString *)stepDescription;


/*!
 @method  stepTimeout
 @abstract  Gets the timeout of this step.
 @discussion  When implemented and returns a valid value, used to define the timeout of this step.  Otherwise, the default timeout is used.
 */
- (NSTimeInterval)stepTimeout;


@end
