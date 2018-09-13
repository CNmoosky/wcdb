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

#ifndef CustomConfig_hpp
#define CustomConfig_hpp

#include <Config.hpp>

namespace WCDB {

class CustomConfig : public Config {
public:
    using Invocation = std::function<bool(Handle *)>;

    CustomConfig(const Invocation &invocation, const Invocation &uninvocation);

    bool invoke(Handle *handle) override;
    bool uninvoke(Handle *handle) override;

protected:
    Invocation m_invocation;
    Invocation m_uninvocation;
};

} //namespace WCDB

#endif /* CustomConfig_hpp */