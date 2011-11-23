//  Created by Nathan Perry.
//


#import <Foundation/Foundation.h>
#import "KIFStepProtocol.h"


@class KIFContext;
@class KIFController;
@class KIFScenario;
@class UIView;


#pragma mark Defines


/**
 @define  KIF_DEFAULT_STEP_TIMEOUT
 @abstract  The default step timeout in seconds for a step
 */
#define KIF_DEFAULT_STEP_TIMEOUT  (10.0)


extern float const KIFDefaultStepTimeout;


#pragma mark Blocks


// Conditional blocks
typedef  BOOL (^KIFConditionalBlock)(void);

// Match blocks
typedef  BOOL (^KIFMatchUIViewBlock)(UIView *view);

// Get blocks
typedef  id             (^KIFGetObjectBlock         )(void);
typedef  NSString *     (^KIFGetStringBlock         )(void);
typedef  NSInteger      (^KIFGetNSIntegerBlock      )(void);
typedef  NSTimeInterval (^KIFGetNSTimeIntervalBlock )(void);


#pragma mark -


@interface KIFStep : NSObject <KIFStep> {
}


#pragma mark stepWith...


#pragma mark stepTo...


/*
 @abstract  Step to tap a view when the block returns true (YES) on a view.
 @param  matchBlock  A block that should return true (YES) when it matches the view to tap.
 */
+ (id)stepToTapViewMatching:(KIFMatchUIViewBlock)matchBlock;


/*
 @abstract  
 @param  getLabelblock  A block that will return the 
 */
+ (id)stepToTapViewMatchingLabelBlock:(KIFGetStringBlock)getLabelBlock;
//  label:(NSString *)label              value:(NSString *)value         traits:(UIAccessibilityTraits)traits             tag:(NSInteger)tag
//  label:(KIFGetStringBlock)labelBlock  value:(KIFGetStringBlock)value  traits:(KIFGetUIAccessibilityTraitsBlock)traits  tag:(KIFGetNSIntegerBlock)tag

+ (id)stepToRunIf:(KIFConditionalBlock)runConditionalBlock  andTapViewMatchingLabelBlock:(KIFGetStringBlock)getLabelBlock;

+ (id)stepToWaitFor:(KIFConditionalBlock)getContinueConditionBlock;
+ (id)stepToWaitTimeInterval:(NSTimeInterval)duration;
+ (id)stepToWaitFromTimeIntervalSinceReferenceData:(KIFGetNSTimeIntervalBlock)getStartTimeBlock  durationTimeInterval:(NSTimeInterval)duration;

+ (id)stepToRunIf:(KIFConditionalBlock)runConditionalBlock  andWaitFor:(KIFConditionalBlock)waitConditionalBlock;
+ (id)stepToSucceedIf:(KIFConditionalBlock)testConditionalBlock;
+ (id)stepToRunIf:(KIFConditionalBlock)runConditionalBlock  andSucceedIf:(KIFConditionalBlock)testConditionalBlock;


#pragma mark runStep...


+ (BOOL)runStep:(KIFStepProtocol *)step
   fromScenario:(KIFScenario *)scenario
 withController:(KIFController *)controller;


+ (BOOL)runStep:(KIFStepProtocol *)step
    withContext:(KIFContext *)context;


#pragma mark KIFStepNotifications Protocol


- (BOOL)shouldRunStep:(KIFContext *)context;


- (BOOL)stepWillBegin:(KIFContext *)context;


- (BOOL)runStep:(KIFContext *)context;


- (void)stepWillTerminate:(KIFContext *)context;


- (NSString *)stepDescription;


- (NSTimeInterval)stepTimeout;


@end
