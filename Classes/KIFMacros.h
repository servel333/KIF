//  Created by Nathan Perry.
//


/*!
 @define KIFTestCondition
 @abstract Tests a condition and returns a failure result if the condition isn't true.
 @discussion This is a useful macro for quickly evaluating conditions in a test step. If the condition is false then the current test step will be aborted with a failure result.
 @param condition The condition to test.
 @param error The NSError object to put the error string into. May be nil, but should usually be the error parameter from the test step execution block.
 @param ... A string describing what the failure was that occurred. This may be a format string with additional arguments.
 */
#define KIFTestCondition(condition, error, ...) ({ \
    if (!(condition)) { \
        if (error) { \
            *error = [[[NSError alloc] initWithDomain:@"KIFTest" code:KIFTestStepResultFailure userInfo:[NSDictionary dictionaryWithObjectsAndKeys:[NSString stringWithFormat:__VA_ARGS__], NSLocalizedDescriptionKey, nil]] autorelease]; \
        } \
    [KIFTestStep stepFailed]; \
    return KIFTestStepResultFailure; \
    } \
})


/*!
 @define KIFTestWaitCondition
 @abstract Tests a condition and returns a wait result if the condition isn't true.
 @discussion This is a useful macro for quickly evaluating conditions in a test step. If the condition is false then the current test step will be aborted with a wait result, indicating that it should be called again in the near future.
 @param condition The condition to test.
 @param error The NSError object to put the error string into. May be nil, but should usually be the error parameter from the test step execution block.
 @param ... A string describing why the step needs to wait. This is important since this reason will be considered the cause of a timeout error if the step requires waiting for too long. This may be a format string with additional arguments.
 */
#define KIFTestWaitCondition(condition, error, ...) ({ \
    if (!(condition)) { \
        if (error) { \
            *error = [[[NSError alloc] initWithDomain:@"KIFTest" code:KIFTestStepResultWait userInfo:[NSDictionary dictionaryWithObjectsAndKeys:[NSString stringWithFormat:__VA_ARGS__], NSLocalizedDescriptionKey, nil]] autorelease]; \
        } \
    return KIFTestStepResultWait; \
    } \
})


/*!
 @definen  WSTestConditionBlock
 @abstract  Simplifies adding test condition steps.
 @param  condition  The condition to test.  Will be wrapped in a block and executed later.
 @discussion
 This macro can be used to simplify adding a test step that is evaluating a condition.  It may be used as an alternative to the verbose and cryptic syntax that it hides.
 
 Example of use:
 
 [KIFTestStep stepWithDescription:@"Description"  executionBlock:TestConditionBlock( 1 == 1 )];
 */
#define KIFTestConditionBlock(condition) ({ \
    ^(KIFTestStep *step, NSError **error) \
    { \
        KIFTestCondition( ( condition ) , error, [step description], @""); \
        return KIFTestStepResultSuccess; \
    }; \
})


/*!
 @definen  KIFTestWaitConditionBlock
 @abstract  Simplifies adding test condition steps.
 @param  condition  The condition to test.  Will be wrapped in a block and executed later.
 @discussion
 This macro can be used to simplify adding a test step that is evaluating a condition.  It may be used as an alternative to the verbose and cryptic syntax that it hides.
 
 Example of use:
 
 [KIFTestStep stepWithDescription:@"Description"  executionBlock:KIFTestWaitConditionBlock( 1 == 1 )];
 */
#define KIFTestWaitConditionBlock(condition) ({ \
    ^(KIFTestStep *step, NSError **error) \
    { \
        KIFTestWaitCondition( ( condition ) , error, [step description], @""); \
        return KIFTestStepResultSuccess; \
    }; \
})

