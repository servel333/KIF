//  Created by Nathan Perry.
//

#import <Foundation/Foundation.h>


@class KIFContext;


#pragma mark -


@protocol KIFControllerNotifications


@optional


- (BOOL)shouldStartTesting:(KIFContext *)context;


- (BOOL)testingWillBegin:(KIFContext *)context;


- (void)testingWillTerminate:(KIFContext *)context;


@end
