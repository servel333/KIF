//
//  UIApplication-KIFAdditions.m
//  KIF
//
//  Created by Eric Firestone on 5/20/11.
//  Licensed to Square, Inc. under one or more contributor license agreements.
//  See the LICENSE file distributed with this work for the terms under
//  which Square, Inc. licenses this file to you.

#import "UIApplication-KIFAdditions.h"
#import "LoadableCategory.h"
#import "UIView-KIFAdditions.h"


MAKE_CATEGORIES_LOADABLE(UIApplication_KIFAdditions)


@implementation UIApplication (KIFAdditions)

- (UIAccessibilityElement *)accessibilityElementWithLabel:(NSString *)label;
{
    return [self accessibilityElementWithLabel:label traits:UIAccessibilityTraitNone];
}

- (UIAccessibilityElement *)accessibilityElementWithLabel:(NSString *)label traits:(UIAccessibilityTraits)traits;
{
    return [self accessibilityElementWithLabel:label accessibilityValue:nil traits:traits];
}

- (UIAccessibilityElement *)accessibilityElementWithLabel:(NSString *)label accessibilityValue:(NSString *)value traits:(UIAccessibilityTraits)traits;
{
    // Go through the array of windows in reverse order to process the frontmost window first.
    // When several elements with the same accessibilitylabel are present the one in front will be picked.
    for (UIWindow *window in [[self windows] reverseObjectEnumerator]) {
        UIAccessibilityElement *element = [window accessibilityElementWithLabel:label accessibilityValue:value traits:traits];
        if (element) {
            return element;
        }
    }
    
    return nil;
}

- (UIAccessibilityElement *)accessibilityElementMatchingBlock:(BOOL(^)(UIAccessibilityElement *))matchBlock;
{
    for (UIWindow *window in [self windows]) {
        UIAccessibilityElement *element = [window accessibilityElementMatchingBlock:matchBlock];
        if (element) {
            return element;
        }
    }
    
    return nil;
}

- (UIAccessibilityElement *)accessibilityElementMatchingRegularExpressionWithPattern:(NSString *)pattern;
{
    
    __block NSError *error = NULL;
    __block NSRegularExpression *regex = [[NSRegularExpression  regularExpressionWithPattern:pattern  options:NSRegularExpressionCaseInsensitive  error:&error] retain];
    
    UIAccessibilityElement * matchingElement = 
            [self  accessibilityElementMatchingBlock:^BOOL(UIAccessibilityElement *element) 
                    {
                        NSUInteger numberOfMatches = 0;
        
                        if (element.accessibilityLabel)
                        {
                            
                            //NSRegularExpression *regex = [NSRegularExpression  regularExpressionWithPattern:pattern  options:NSRegularExpressionCaseInsensitive  error:&error];
                            numberOfMatches = [regex  numberOfMatchesInString:element.accessibilityLabel  options:0  range:NSMakeRange(0, [element.accessibilityLabel length])];
                            
                        }
                        
                        return ( 0 < numberOfMatches );
                    }];
    
    [regex release];
    return matchingElement;
}

- (BOOL)isAccessibilityInspectorEnabled;
{
    UIWindow *keyWindow = [self keyWindow];
    NSString *originalAccessibilityLabel = [keyWindow accessibilityLabel];
    
    [keyWindow setAccessibilityLabel:@"KIF Test Label"];
    BOOL isInspectorEnabled = [[keyWindow accessibilityLabel] isEqualToString:@"KIF Test Label"];
    
    [keyWindow setAccessibilityLabel:originalAccessibilityLabel];
    
    return isInspectorEnabled;
}

- (BOOL)tapAtScreenPoint:(CGPoint)point
{
    UIView *view = nil;
    
    // Try all the windows until we get one back that actually has something in it at the given point
    for (UIWindow *window in [[self windows] reverseObjectEnumerator]) {
        
        CGPoint windowPoint = [window convertPoint:point fromView:nil];
        view = [window hitTest:windowPoint withEvent:nil];
        
        // If we hit the window itself, then skip it.
        if (view == window || view == nil) {
            continue;
        }
    }
    
    if (!view)
    {
        NSLog(@"No view was found at the point %@", NSStringFromCGPoint(point));
        return NO;
    }
    
    // This is mostly redundant of the test in _accessibilityElementWithLabel:
    CGPoint viewPoint = [view convertPoint:point fromView:nil];
    [view tapAtPoint:viewPoint];
    
    return YES;
}

- (UIViewController *)controllerWithClassName:(NSString *)controllerClassName  forViewWithClassName:(NSString *)viewClassName;
{
    for (UIWindow *window in [self windows]) {
        UIViewController *controller = [window controllerWithClassName:controllerClassName  forViewWithClassName:viewClassName];
        if (controller) {
            return controller;
        }
    }
    
    return nil;
}

- (UIView *)viewWithClassName:(NSString *)className;
{
    for (UIWindow *window in [self windows]) {
        UIView * view = [window viewWithClassName:className];
        if (view) {
            return view;
        }
    }
    
    return nil;
}

- (UIWindow *)keyboardWindow;
{
    for (UIWindow *window in [self windows]) {
        if ([NSStringFromClass([window class]) isEqual:@"UITextEffectsWindow"]) {
            return window;
        }
    }
    
    return nil;
}

- (UIWindow *)pickerViewWindow;
{
    for (UIWindow *window in [self windows]) {
        UIView *pickerView = [window subviewWithClassNameOrSuperClassNamePrefix:@"UIPickerView"];
        if (pickerView) {
            return window;
        }
    }
    
    return nil;
}

@end
