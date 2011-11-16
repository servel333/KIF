//  Created by Nathan Perry.
//


#import <Foundation/Foundation.h>


@class KIFController;
@class KIFScenario;


@interface KIFScenarioContext : NSObject {
    KIFController *_controller;
    KIFScenario *_scenario;
}


@property (nonatomic, readonly) KIFController *controller;


@property (nonatomic, readonly) KIFScenario *scenario;


@end
