//  Created by Nathan Perry.
//


#import <Foundation/Foundation.h>


@protocol KIFStepNotifications;


@interface KIFStepMutableArray : NSMutableArray


@property (nonatomic, readonly) KIFStepNotifications *previousStep;
@property (nonatomic, readonly) KIFStepNotifications *currentStep;
@property (nonatomic, readonly) KIFStepNotifications *nextStep;


@end
