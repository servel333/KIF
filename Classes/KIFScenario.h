//  Created by Nathan Perry.
//


#import <Foundation/Foundation.h>


@class KIFContext;
@protocol KIFStepNotifications;


@interface KIFScenario : NSObject {
    NSArray *_steps;
}


@property (nonatomic, readonly) NSArray *steps;


@end
