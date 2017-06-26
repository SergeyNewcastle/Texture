//
//  ASLog.h
//  Texture
//
//  Copyright (c) 2014-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under the BSD-style license found in the
//  LICENSE file in the /ASDK-Licenses directory of this source tree. An additional
//  grant of patent rights can be found in the PATENTS file in the same directory.
//
//  Modifications to this file made after 4/13/2017 are: Copyright (c) 2017-present,
//  Pinterest, Inc.  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//

#import <AsyncDisplayKit/ASAvailability.h>
#import <AsyncDisplayKit/ASBaseDefines.h>
#import <Foundation/Foundation.h>
#import <os/log.h>
#import <os/activity.h>

/**
 * The activity tracing system changed a lot between iOS 9 and 10.
 * In iOS 10, the system was merged with logging and became much more powerful
 * and adopted a new API.
 *
 * The legacy API is visible, but its functionality is extremely limited and the API is so different
 * that we don't bother with it. For example, activities described by os_activity_start/end are not
 * reflected in the log whereas activities described by the newer
 * os_activity_scope are. So unfortunately we must use these iOS 10
 * APIs to get meaningful logging data.
 */
#if OS_LOG_TARGET_HAS_10_12_FEATURES

#define OS_ACTIVITY_NULLABLE nullable
#define as_activity_scope(activity)                               os_activity_scope(activity)
#define as_activity_apply(activity, block)                        os_activity_apply(activity, block)
#define as_activity_create(description, parent_activity, flags)   os_activity_create(description, parent_activity, flags)

#else

#define OS_ACTIVITY_NULLABLE
#define as_activity_scope(activity)
#define as_activity_apply(activity, block)
#define as_activity_create(description, parent_activity, flags)   (os_activity_t)0

#endif

// Log the current backtrace. Note: the backtrace will be leaked. Only call this when debugging or in case of failure.
#define as_log_backtrace(log) as_log_debug(log, "backtrace: %p", CFBridgingRetain(NSThread.callStackSymbols));

/**
 * The logging macros are not guarded by deployment-target checks like the activity macros are, but they are
 * only available on iOS >= 9 at runtime, so just make them conditional.
 */
#define as_log_create(subsystem, category)  (AS_AT_LEAST_IOS9 ? os_log_create(subsystem, category) : (os_log_t)0)
#define as_log_debug(log, format, ...)      (AS_AT_LEAST_IOS9 ? os_log_debug(log, format, ##__VA_ARGS__) : (void)0)
#define as_log_info(log, format, ...)       (AS_AT_LEAST_IOS9 ? os_log_info(log, format, ##__VA_ARGS__) : (void)0)
#define as_log_error(log, format, ...)      (AS_AT_LEAST_IOS9 ? os_log_error(log, format, ##__VA_ARGS__) : (void)0)
#define as_log_fault(log, format, ...)      (AS_AT_LEAST_IOS9 ? os_log_fault(log, format, ##__VA_ARGS__) : (void)0)

ASDISPLAYNODE_EXTERN_C_BEGIN

/// Global disable for all logs except APILog.
#define ASInternalLogsDisabled 0

/// The log for issues with API usage that are minor enough not to be assertion failures.
#define ASAPILogEnabled 1
os_log_t ASAPILog();

#define ASLayoutLogEnabled 1
os_log_t ASLayoutLog();

#define ASRenderLogEnabled 1
os_log_t ASRenderLog();

#define ASCollectionLogEnabled 1
os_log_t ASCollectionLog();

#define ASMultiplexImageLogEnabled 1
os_log_t ASMultiplexImageLog();

#define ASMainThreadDeallocationLogEnabled 0 // Too chatty to enable by default.
os_log_t ASMainThreadDeallocationLog();

#define ASPedanticLogEnabled 0
os_log_t ASPedanticLog();


ASDISPLAYNODE_EXTERN_C_END
