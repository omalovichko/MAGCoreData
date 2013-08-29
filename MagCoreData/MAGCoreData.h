//
//  MAGCoreData.h
//  MAGCoreDataExample
//
//  Created by Ievgen Rudenko on 8/28/13.
//  Copyright (c) 2013 MadAppGang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MAGCoreData : NSObject

+(instancetype)instance;

//default is YES
@property (nonatomic) BOOL autoMergeFromChildContexts;

#pragma mark - Initialisation
+(NSError *)initCoreData;
+(BOOL)initCoreDataWithModelNAme:(NSString *)modelName error:(NSError **)error;
+(BOOL)initCoreDataWithModelName:(NSString *)modelName andStorageName:(NSString*)storageName error:(NSError **)error;
-(void)close;

#pragma mark - Management Object Context
//Main Context
+(NSManagedObjectContext *)context;
+(NSManagedObjectContext *)createPrivateContext;
//save main context
+(void)save;
+(void)saveContext:(NSManagedObjectContext*)context;
//Delete all data from first persistent store in persistent store coordinator
+(void)deleteAll;



@end
