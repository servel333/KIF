//  Created by Nathan Perry.
//

#import <Foundation/Foundation.h>


@class KIFControllerContext;


#pragma mark -


@protocol KIFControllerNotifications


@optional


- (BOOL)shouldStartTesting:(KIFControllerContext *)context;


- (BOOL)testingWillBegin:(KIFControllerContext *)context;


- (void)testingWillTerminate:(KIFControllerContext *)context;


@end
