//  Created by Nathan Perry.
//


#import "KIFMutableContext.h"

#import "KIF.h"


@implementation KIFMutableContext


- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


#pragma mark Convenience constructors


+ (id)context
{
    return [[[self alloc] init] autorelease];
}


#pragma mark Setters


- (void)setController:(KIFController *)controller
{
    [_controller release];
    _controller = controller;
    [_controller retain];
}


- (void)setScenario:(KIFScenario *)scenario;
{
    [_scenario release];
    _scenario = scenario;
    [_scenario retain];
}


- (void)setStep:(NSObject<KIFStepNotifications> *)step;
{
    [_step release];
    _step = step;
    [_step retain];
}


- (void)setFirstRunStep:(NSTimeInterval)firstRanStep;
{
    _firstRanStep = firstRanStep;
}


- (void)setLastRunStep:(NSTimeInterval)lastRanStep;
{
    _lastRanStep = lastRanStep;
}


#pragma mark Properties


@synthesize controller = _controller;
@synthesize scenario = _scenario;
@synthesize step = _step;
@synthesize firstRanStep = _firstRanStep;
@synthesize lastRanStep = _lastRanStep;


@end
