//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#include <mayaUsd_Schemas/ALMayaReference.h>

#include <pxr/base/tf/pyContainerConversions.h>
#include <pxr/base/tf/pyResultConversions.h>
#include <pxr/base/tf/pyUtils.h>
#include <pxr/base/tf/wrapTypeHelpers.h>
#include <pxr/usd/sdf/primSpec.h>
#include <pxr/usd/usd/pyConversions.h>
#include <pxr/usd/usd/schemaBase.h>

#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <boost/python/operators.hpp>
#include <boost/python/self.hpp>

#include <string>

using namespace boost::python;

PXR_NAMESPACE_USING_DIRECTIVE

namespace {

#define WRAP_CUSTOM template <class Cls> static void _CustomWrapCode(Cls& _class)

// fwd decl.
WRAP_CUSTOM;

} // anonymous namespace

void wrapMayaUsd_SchemasALMayaReference()
{
    typedef MayaUsd_SchemasALMayaReference This;

    class_<This, bases<MayaUsd_SchemasMayaReference>> cls("ALMayaReference");

    cls.def(init<UsdPrim>(arg("prim")))
        .def(init<UsdSchemaBase const&>(arg("schemaObj")))
        .def(TfTypePythonClass())

        .def("Get", &This::Get, (arg("stage"), arg("path")))
        .staticmethod("Get")

        .def("Define", &This::Define, (arg("stage"), arg("path")))
        .staticmethod("Define")

        .def(
            "GetSchemaAttributeNames",
            &This::GetSchemaAttributeNames,
            arg("includeInherited") = true,
            return_value_policy<TfPySequenceToList>())
        .staticmethod("GetSchemaAttributeNames")

        .def(
            "_GetStaticTfType",
            (TfType const& (*)())TfType::Find<This>,
            return_value_policy<return_by_value>())
        .staticmethod("_GetStaticTfType")

        .def(!self)

        ;

    _CustomWrapCode(cls);
}

// ===================================================================== //
// Feel free to add custom code below this line, it will be preserved by
// the code generator.  The entry point for your custom code should look
// minimally like the following:
//
// WRAP_CUSTOM {
//     _class
//         .def("MyCustomMethod", ...)
//     ;
// }
//
// Of course any other ancillary or support code may be provided.
//
// Just remember to wrap code in the appropriate delimiters:
// 'namespace {', '}'.
//
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--

namespace {

WRAP_CUSTOM { }

} // namespace
