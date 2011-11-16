//  Created by Nathan Perry.
//


#import <Foundation/Foundation.h>


@class KIFController;


@interface KIFControllerContext : NSObject {
    KIFController *_controller;
}


@property (nonatomic, readonly) KIFController *controller;


@end