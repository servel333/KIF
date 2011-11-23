//  Created by Nathan Perry.
//


#import <Foundation/Foundation.h>


typedef NSString*  KIFUserDataKeyType;
typedef id         KIFUserDataValueType;


#pragma mark -


/**
 @abstract  A key-value pair listing of user data associated with the scenario.
 @discussion
 This method provides the ability for the user to save and retrieve data between steps.
 */
@interface KIFUserData : NSObject {
    NSMutableDictionary *_dictionary;
}


@end


#pragma mark -


@interface KIFUserData (NSDictionaryMethods)


- (NSArray *)allKeys;
- (NSArray *)allKeysForObject:(KIFUserDataValueType)anObject;    
- (NSArray *)allValues;
- (NSEnumerator *)objectEnumerator;
- (NSArray *)objectsForKeys:(NSArray *)keys notFoundMarker:(KIFUserDataValueType)marker;

- (NSArray *)keysSortedByValueUsingSelector:(SEL)comparator;
- (void)getObjects:(KIFUserDataValueType *)objects andKeys:(KIFUserDataKeyType *)keys;

- (void)removeObjectForKey:(KIFUserDataKeyType)aKey;
- (void)setObject:(KIFUserDataValueType)anObject forKey:(KIFUserDataKeyType)aKey;

- (void)addEntriesFromDictionary:(NSDictionary *)otherDictionary;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray *)keyArray;
- (void)setDictionary:(NSDictionary *)otherDictionary;


@end
