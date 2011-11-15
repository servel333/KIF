//
//  KIFTestStep.m
//  KIF
//
//  Licensed to Square, Inc. under one or more contributor license agreements.
//  See the LICENSE file distributed with this work for the terms under
//  which Square, Inc. licenses this file to you.


#import <QuartzCore/QuartzCore.h>
#import "KIFTestStep.h"
#import "CGGeometry-KIFAdditions.h"
#import "UIAccessibilityElement-KIFAdditions.h"
#import "UIApplication-KIFAdditions.h"
#import "UIScrollView-KIFAdditions.h"
#import "UITouch-KIFAdditions.h"
#import "UIView-KIFAdditions.h"
#import "UIWindow-KIFAdditions.h"


@implementation KIFCore


+ (KIFTestStepResult)getWaitUntTimeInterval:(NSTimeInterval)interval  expiresFromStartTime:(NSTimeInterval)start;
{
    if ([NSDate timeIntervalSinceReferenceDate] - quiesceStartTime) >= quiesceWaitInterval
}


+ (id)tapViewWithAccessibilityLabel:(NSString *)label value:(NSString *)value traits:(UIAccessibilityTraits)traits;
{
    NSString *description = nil;
    if (value.length) {
        description = [NSString stringWithFormat:@"Tap view with accessibility label \"%@\" and accessibility value \"%@\"", label, value];
    } else {
        description = [NSString stringWithFormat:@"Tap view with accessibility label \"%@\"", label];
    }
    
    // After tapping the view we want to wait a short period to allow things to settle (animations and such). We can't do this using CFRunLoopRunInMode() because certain things, such as the built-in media picker, do things with the run loop that are not compatible with this kind of wait. Instead we leverage the way KIF hooks into the existing run loop by returning "wait" results for the desired period.
    const NSTimeInterval quiesceWaitInterval = 0.5;
    __block NSTimeInterval quiesceStartTime = 0.0;
    
    __block UIView *view = nil;
    
    return [self stepWithDescription:description executionBlock:^(KIFTestStep *step, NSError **error) {
        
        // If we've already tapped the view and stored it to a variable, and we've waited for the quiesce time to elapse, then we're done.
        if (view) {
            KIFTestWaitCondition(([NSDate timeIntervalSinceReferenceDate] - quiesceStartTime) >= quiesceWaitInterval, error, @"Waiting for view to become the first responder.");
            return KIFTestStepResultSuccess;
        }
        
        UIAccessibilityElement *element = [self _accessibilityElementWithLabel:label accessibilityValue:value tappable:YES traits:traits error:error];
        if (!element) {
            return KIFTestStepResultWait;
        }
        
        view = [UIAccessibilityElement viewContainingAccessibilityElement:element];
        KIFTestWaitCondition(view, error, @"Failed to find view for accessibility element with label \"%@\"", label);
        KIFTestWaitCondition([self _isUserInteractionEnabledForView:view], error, @"View with accessibility label \"%@\" is not enabled for interaction", label);
        
        CGRect elementFrame = [view.window convertRect:element.accessibilityFrame toView:view];
        CGPoint tappablePointInElement = [view tappablePointInRect:elementFrame];
        
        // This is mostly redundant of the test in _accessibilityElementWithLabel:
        KIFTestWaitCondition(!isnan(tappablePointInElement.x), error, @"The element with accessibility label %@ is not tappable", label);
        [view tapAtPoint:tappablePointInElement];
        
        KIFTestCondition(![view canBecomeFirstResponder] || [view isDescendantOfFirstResponder], error, @"Failed to make the view %@ which contains the accessibility element \"%@\" into the first responder", view, label);
        
        quiesceStartTime = [NSDate timeIntervalSinceReferenceDate];
        
        KIFTestWaitCondition(NO, error, @"Waiting for the view to settle.");
    }];
}


@end
