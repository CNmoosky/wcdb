/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <WCDB/Interface.h>
#import <WCDB/NSString+CppString.h>

static_assert((int) WCTErrorTypeError == WCDB::Error::type, "");
static_assert((int) WCTErrorTypeSQLite == WCDB::SQLiteError::type, "");
static_assert((int) WCTErrorTypeHandle == WCDB::HandleError::type, "");
static_assert((int) WCTErrorTypeCore == WCDB::CoreError::type, "");
static_assert((int) WCTErrorTypeFile == WCDB::FileError::type, "");
static_assert(((1 << WCDB::Error::type) & (1 << WCDB::SQLiteError::type) & (1 << WCDB::HandleError::type) & (1 << WCDB::CoreError::type) & (1 << WCDB::FileError::type)) == 0, "");

static_assert((int) WCTErrorLevelIgnore == (int) WCDB::Error::Level::Ignore, "");
static_assert((int) WCTErrorLevelDebug == (int) WCDB::Error::Level::Debug, "");
static_assert((int) WCTErrorLevelWarning == (int) WCDB::Error::Level::Warning, "");
static_assert((int) WCTErrorLevelError == (int) WCDB::Error::Level::Error, "");
static_assert((int) WCTErrorLevelFatal == (int) WCDB::Error::Level::Fatal, "");

@implementation WCTError

- (instancetype)initWithError:(const WCDB::Error &)error
{
    if (self = [super initWithDomain:@"WCDB"
                                code:error.code
                            userInfo:nil]) {
        _message = [NSString stringWithCppString:error.message];
        _level = (WCTErrorLevel) error.level;
    }
    return self;
}

- (WCTErrorType)type
{
    return WCTErrorTypeError;
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"[%s]Code: %ld, Msg: %@", WCDB::Error::LevelName((WCDB::Error::Level) _level), (long) self.code, self.message];
}

@end