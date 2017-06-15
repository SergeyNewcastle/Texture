//
//  ASLog.m
//  AsyncDisplayKit
//
//  Created by Adlai Holler on 6/21/17.
//  Copyright © 2017 Facebook. All rights reserved.
//

#import <AsyncDisplayKit/ASLog.h>

os_log_t ASAPILog() {
  static os_log_t log;
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
#if ASAPILogEnabled
    log = as_log_create("org.TextureGroup.Texture", "API");
#endif
  });
  return log;
}

os_log_t ASLayoutLog() {
  static os_log_t log;
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
#if !ASInternalLogsDisabled && ASLayoutLogEnabled
    log = as_log_create("org.TextureGroup.Texture", "Layout");
#endif
  });
  return log;
}

os_log_t ASCollectionLog() {
  static os_log_t log;
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
#if !ASInternalLogsDisabled && ASCollectionLogEnabled
    log = as_log_create("org.TextureGroup.Texture", "Collection");
#endif
  });
  return log;
}

os_log_t ASRenderLog() {
  static os_log_t log;
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
#if !ASInternalLogsDisabled && ASRenderLogEnabled
    log = as_log_create("org.TextureGroup.Texture", "Render");
#endif
  });
  return log;
}

os_log_t ASMultiplexImageLog() {
  static os_log_t log;
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
#if !ASInternalLogsDisabled && ASMultiplexImageLogEnabled
    log = as_log_create("org.TextureGroup.Texture", "MultiplexImage");
#endif
  });
  return log;
}

os_log_t ASMainThreadDeallocationLog() {
  static os_log_t log;
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
#if !ASInternalLogsDisabled && ASMainThreadDeallocationLogEnabled
    log = as_log_create("org.TextureGroup.Texture", "MainDealloc");
#endif
  });
  return log;
}

os_log_t ASPedanticLog() {
  static os_log_t log;
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
#if !ASInternalLogsDisabled && ASPedanticLogEnabled
    log = as_log_create("org.TextureGroup.Texture", "Pedantic");
#endif
  });
  return log;
}
