//===-- DynamicLoaderWasmDYLD.h ------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef liblldb_Plugins_Process_Wasm_DynamicLoaderWasmDYLD_h_
#define liblldb_Plugins_Process_Wasm_DynamicLoaderWasmDYLD_h_

#include "lldb/Target/DynamicLoader.h"
#include "lldb/lldb-forward.h"

#include <map>

namespace lldb_private {

class DynamicLoaderWasmDYLD : public DynamicLoader {
public:
  DynamicLoaderWasmDYLD(Process *process);

  ~DynamicLoaderWasmDYLD() override;

  static void Initialize();
  static void Terminate();
  static ConstString GetPluginNameStatic();
  static const char *GetPluginDescriptionStatic();

  static DynamicLoader *CreateInstance(Process *process, bool force);

  lldb::ModuleSP LoadModuleAtAddress(const lldb_private::FileSpec &file,
                                     lldb::addr_t link_map_addr,
                                     lldb::addr_t base_addr,
                                     bool base_addr_is_offset) override;
  void DidAttach() override;
  void DidLaunch() override;
  Status CanLoadImage() override;
  lldb::ThreadPlanSP GetStepThroughTrampolinePlan(Thread &thread,
                                                  bool stop) override;

  ConstString GetPluginName() override;
  uint32_t GetPluginVersion() override;

private:
  std::map<lldb::ModuleSP, lldb::addr_t> m_loaded_modules;
};

} // namespace lldb_private

#endif // liblldb_Plugins_Process_Wasm_DynamicLoaderWasmDYLD_h_
