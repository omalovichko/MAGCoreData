//
//  MAGCoreData.h
//  MAGCoreDataExample
//
//  Created by Ievgen Rudenko on 8/28/13.
//  Copyright (c) 2013 MadAppGang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


#ifdef MAGCOREDATA_LOGGING_ENABLED
#define MAGCoreDataLog(frmt, ...) NSLog(frmt, ##__VA_ARGS__)
#else
#define MAGCoreDataLog(frmt, ...) ((void)0)
#endif


NS_ASSUME_NONNULL_BEGIN

@interface MAGCoreData : NSObject

+ (instancetype)instance;

@property (nonatomic, assign) BOOL autoMergeFromChildContexts; //default is NO

#pragma mark - Initialisation
+ (NSError * __nullable)prepareCoreData;
+ (BOOL)prepareCoreDataWithModelName:(NSString * __nullable)modelName error:(NSError **)error;
+ (BOOL)prepareCoreDataWithModelName:(NSString * __nullable)modelName andStorageName:(NSString * __nullable)storageName error:(NSError **)error;

#pragma mark - Management Object Context
+ (NSManagedObjectContext * __nullable)context; // Main Context
+ (NSManagedObjectContext * __nullable)createPrivateContext;

#pragma mark - Saving
+ (BOOL)save; // Save main context
+ (BOOL)saveContext:(NSManagedObjectContext *)context;

#pragma mark -
- (void)close;
+ (BOOL)deleteAll; // Delete all data from first persistent store in persistent store coordinator
+ (BOOL)deleteAllInStorageWithName:(NSString *)string;


#pragma mark - Fetching managed objects

@end

NS_ASSUME_NONNULL_END
