//  Created by Nathan Perry.
//


#import <Foundation/Foundation.h>


@class KIFStepContext;
@protocol KIFStepNotifications;


typedef BOOL(^KIFConditionalBlock)(void);
typedef NSString *(^KIFGetLabelBlock)(void);


@interface KIFStep : NSObject <KIFStepNotifications> {
}


#pragma mark stepWith...


#pragma mark stepTo...


+ (id)stepToTapViewWithLabelBlock:(KIFGetLabelBlock)getLabelBlock;


+ (id)stepToTest:(KIFConditionalBlock)conditionalBlock;


#pragma mark KIFStepNotifications Protocol


- (BOOL)shouldRunStep:(KIFStepContext *)context;


- (BOOL)stepWillBegin:(KIFStepContext *)context;


- (BOOL)runStep:(KIFStepContext *)context;


- (void)stepWillTerminate:(KIFStepContext *)context;


- (NSString *)stepDescription;


- (NSTimeInterval)stepTimeout;


@end
