//  Created by Nathan Perry.
//


#import "KIFUserData.h"


@interface KIFUserData ()


@property (nonatomic) NSMutableDictionary *dictionary;


@end


#pragma mark -


@implementation KIFUserData


- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


#pragma mark Properties


@synthesize dictionary = _dictionary;


#pragma mark KIFUserData (NSDictionaryMethods)


- (NSArray *)allKeys
{
    return [_dictionary  allKeys];
}


- (NSArray *)allKeysForObject:(KIFUserDataValueType)anObject
{
    return [_dictionary  allKeysForObject:anObject];
}


- (NSArray *)allValues
{
    return [_dictionary  allValues];
}


- (NSEnumerator *)objectEnumerator
{
    return [_dictionary  objectEnumerator];
}


- (NSArray *)objectsForKeys:(NSArray *)keys notFoundMarker:(KIFUserDataValueType)marker
{
    return [_dictionary  objectsForKeys:keys  notFoundMarker:marker];
}


- (NSArray *)keysSortedByValueUsingSelector:(SEL)comparator
{
    return [_dictionary  keysSortedByValueUsingSelector:comparator];
}


- (void)getObjects:(KIFUserDataValueType *)objects andKeys:(KIFUserDataKeyType *)keys
{
    return [_dictionary  getObjects:objects  andKeys:keys];
}


- (void)removeObjectForKey:(KIFUserDataKeyType)aKey
{
    return [_dictionary  removeObjectForKey:aKey];
}


- (void)setObject:(KIFUserDataValueType)anObject forKey:(KIFUserDataKeyType)aKey
{
    return [_dictionary  setObject:anObject  forKey:aKey];
}


- (void)addEntriesFromDictionary:(NSDictionary *)otherDictionary
{
    return [_dictionary  addEntriesFromDictionary:otherDictionary];
}


- (void)removeAllObjects
{
    return [_dictionary  removeAllObjects];
}


- (void)removeObjectsForKeys:(NSArray *)keyArray
{
    return [_dictionary  removeObjectsForKeys:keyArray];
}


- (void)setDictionary:(NSDictionary *)otherDictionary
{
    return [_dictionary  setDictionary:otherDictionary];
}


@end
