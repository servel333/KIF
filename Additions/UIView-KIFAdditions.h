//
//  UIView-KIFAdditions.h
//  KIF
//
//  Created by Eric Firestone on 5/20/11.
//  Licensed to Square, Inc. under one or more contributor license agreements.
//  See the LICENSE file distributed with this work for the terms under
//  which Square, Inc. licenses this file to you.

#import <UIKit/UIKit.h>


@interface UIView (KIFAdditions)

@property (nonatomic, readonly, getter=isTappable) BOOL tappable;

- (BOOL)isDescendantOfFirstResponder;
- (UIAccessibilityElement *)accessibilityElementWithLabel:(NSString *)label;
- (UIAccessibilityElement *)accessibilityElementWithLabel:(NSString *)label traits:(UIAccessibilityTraits)traits;
- (UIAccessibilityElement *)accessibilityElementWithLabel:(NSString *)label accessibilityValue:(NSString *)value traits:(UIAccessibilityTraits)traits;

/*!
 @method  controllerWithClassName:forResponder:
 @abstract  Finds the named controller for the responder.
 @param  controllerClassName  The named controller to search for.
 @param  responder  The responder to attempt to match and then get the next responder from.
 @result  The found controller or nil.
 @discussion  Attempts to identify the specified responder as the named controler.  If there is no match, continues searching the next responder using recursion.
 */
+ (UIViewController *)controllerWithClassName:(NSString *)controllerClassName  forResponder:(UIResponder *)responder;

/*!
 @method  controllerWithClassName:forViewWithClassName:
 @abstract  Finds the named controller of the named view.
 @param  controllerClassName  The named controller to search for.
 @param  viewClassName  The named view to search for.
 @result  The named controller or nil.
 @discussion  Searches through the view hierarchy for the named view, then searches the views responders for the named controller.
 */
- (UIViewController *)controllerWithClassName:(NSString *)controllerClassName  forViewWithClassName:(NSString *)viewClassName;

/*!
 @method  viewWithClassName:
 @abstract  Finds the named descendent view.
 @param  className  The named class to search for.
 @result  The named class or nil.
 */
- (UIView *)viewWithClassName:(NSString *)className;

/*!
 @method accessibilityElementMatchingBlock:
 @abstract Finds the descendent accessibility element that matches the conditions defined by the match block.
 @param matchBlock A block which returns YES for matching elements.
 @result The matching accessibility element.
 */
- (UIAccessibilityElement *)accessibilityElementMatchingBlock:(BOOL(^)(UIAccessibilityElement *))matchBlock;

- (UIView *)subviewWithClassNamePrefix:(NSString *)prefix;
- (UIView *)subviewWithClassNameOrSuperClassNamePrefix:(NSString *)prefix;

- (void)flash;
- (void)tap;
- (void)tapAtPoint:(CGPoint)point;
- (void)dragFromPoint:(CGPoint)startPoint toPoint:(CGPoint)endPoint;
- (void)dragAlongPathWithPoints:(CGPoint *)points count:(NSInteger)count;

/*!
 @method isTappableWithHitTestResultView:
 @abstract Easy hook to override whether a hit test result makes a view tappable.
 @discussion Some times, your view hierarchies involve putting overlays over views that would otherwise be tappable. Since KIF doesn't know about these exceptions, you can override this method as a convenient way of hooking in to the check for something being tappable. Your implementation will probably want to call up to super.
 @param hitView The view -hitTest: returned when trying to tap on a point inside your view's bounds
 @result Whether or not the view is tappable.
 */
- (BOOL)isTappableWithHitTestResultView:(UIView *)hitView;

/*!
 @method isTappableInRect:
 @abstract Whether or not the receiver can be tapped inside the given rectangular area.
 @discussion Determines whether or not tapping within the given rectangle would actually hit the receiver or one of its children. This is useful for determining if the view is actually on screen and enabled.
 @param rect A rectangle specifying an area in the receiver in the receiver's frame coordinates.
 @result Whether or not the view is tappable.
 */
- (BOOL)isTappableInRect:(CGRect)rect;

/*!
 @method tappablePointInRect:(CGRect)rect;
 @abstract Finds a point in the receiver that is tappable.
 @discussion Finds a tappable point in the receiver, where tappable is defined as a point that, when tapped, will hit the receiver.
 @param rect A rectangle specifying an area in the receiver in the receiver's frame coordinates.
 @result A tappable point in the receivers frame coordinates.
 */
- (CGPoint)tappablePointInRect:(CGRect)rect;

@end
