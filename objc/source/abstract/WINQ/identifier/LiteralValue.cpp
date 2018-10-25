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

#include <WCDB/WINQ.h>

namespace WCDB {

LiteralValue::LiteralValue(int32_t value)
{
    syntax.switcher = SyntaxType::Switch::Integer;
    syntax.integerValue = value;
}

LiteralValue::LiteralValue(int64_t value)
{
    syntax.switcher = SyntaxType::Switch::Integer;
    syntax.integerValue = value;
}

LiteralValue::LiteralValue(double value)
{
    syntax.switcher = SyntaxType::Switch::Float;
    syntax.floatValue = value;
}

LiteralValue::LiteralValue(std::nullptr_t)
{
    syntax.switcher = SyntaxType::Switch::Null;
}

LiteralValue::LiteralValue(const char* value)
{
    syntax.switcher = SyntaxType::Switch::String;
    syntax.stringValue = value;
}

LiteralValue LiteralValue::currentTime()
{
    LiteralValue value;
    value.syntax.switcher = SyntaxType::Switch::CurrentTime;
    return value;
}

LiteralValue LiteralValue::currentDate()
{
    LiteralValue value;
    value.syntax.switcher = SyntaxType::Switch::CurrentDate;
    return value;
}

LiteralValue LiteralValue::currentTimestamp()
{
    LiteralValue value;
    value.syntax.switcher = SyntaxType::Switch::CurrentTimestamp;
    return value;
}

} // namespace WCDB