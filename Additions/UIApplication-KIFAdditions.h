//
//  UIApplication-KIFAdditions.h
//  KIF
//
//  Created by Eric Firestone on 5/20/11.
//  Licensed to Square, Inc. under one or more contributor license agreements.
//  See the LICENSE file distributed with this work for the terms under
//  which Square, Inc. licenses this file to you.

#import <UIKit/UIKit.h>


@interface UIApplication (KIFAdditions)

- (UIAccessibilityElement *)accessibilityElementWithLabel:(NSString *)label;
- (UIAccessibilityElement *)accessibilityElementWithLabel:(NSString *)label traits:(UIAccessibilityTraits)traits;
- (UIAccessibilityElement *)accessibilityElementWithLabel:(NSString *)label accessibilityValue:(NSString *)value traits:(UIAccessibilityTraits)traits;
- (UIAccessibilityElement *)accessibilityElementMatchingBlock:(BOOL(^)(UIAccessibilityElement *))matchBlock;
- (UIAccessibilityElement *)accessibilityElementMatchingRegularExpressionWithPattern:(NSString *)pattern;

/**
 @method  isAccessibilityInspectorEnabled
 @abstract  Gets a value indicating if the accessibility inspector is enabled.
 @discussion  This method for testing if the inspector is enabled was taken from the Frank framework.  https://github.com/moredip/Frank
 */
- (BOOL)isAccessibilityInspectorEnabled;

/**
 @method  tapAtScreenPoint:
 @abstract  Finds a tappable view at the point and taps it.
 @param  point  The point to tap, in screen cordornates.
 @result  true (YES) if successfully tapped a view at the point; otherwise false (NO).
 */
- (BOOL)tapAtScreenPoint:(CGPoint)point;

/**
 @method  controllerWithClassName:forViewWithClassName:
 @abstract  Finds the named controller of the named view.
 @param  controllerClassName  The named controller to search for.
 @param  viewClassName  The named view to search for.
 @result  The named controller or nil.
 @discussion  Searches through the view hierarchy for the named view, then searches the views responders for the named controller.
 */
- (UIViewController *)controllerWithClassName:(NSString *)controllerClassName  forViewWithClassName:(NSString *)viewClassName;

/**
 @method  viewWithClassName:
 @abstract  Finds the named descendent view.
 @param  className  The named class to search for.
 @result  The named class or nil.
 */
- (UIView *)viewWithClassName:(NSString *)className;

- (UIWindow *)keyboardWindow;
- (UIWindow *)pickerViewWindow;

@end
