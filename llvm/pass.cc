#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <map>
#include <set>
#include <algorithm>

#include <llvm/ADT/Statistic.h>
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/Debug.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

 #include "llvm/Transforms/Scalar/ADCE.h"
 #include "llvm/ADT/DenseMap.h"
 #include "llvm/ADT/DepthFirstIterator.h"
 #include "llvm/ADT/GraphTraits.h"
 #include "llvm/ADT/MapVector.h"
 #include "llvm/ADT/PostOrderIterator.h"
 #include "llvm/ADT/SetVector.h"
 #include "llvm/ADT/SmallPtrSet.h"
 #include "llvm/ADT/SmallVector.h"
 #include "llvm/ADT/Statistic.h"
 #include "llvm/Analysis/GlobalsModRef.h"
 #include "llvm/Analysis/IteratedDominanceFrontier.h"
 #include "llvm/Analysis/PostDominators.h"
 #include "llvm/IR/BasicBlock.h"
 #include "llvm/IR/CFG.h"
 #include "llvm/IR/DebugInfoMetadata.h"
 #include "llvm/IR/DebugLoc.h"
 #include "llvm/IR/Dominators.h"
 #include "llvm/IR/Function.h"
 #include "llvm/IR/IRBuilder.h"
 #include "llvm/IR/InstIterator.h"
 #include "llvm/IR/InstrTypes.h"
 #include "llvm/IR/Instruction.h"
 #include "llvm/IR/Instructions.h"
 #include "llvm/IR/IntrinsicInst.h"
 #include "llvm/IR/PassManager.h"
 #include "llvm/IR/Use.h"
 #include "llvm/IR/Value.h"
 #include "llvm/InitializePasses.h"
 #include "llvm/Pass.h"
 #include "llvm/ProfileData/InstrProf.h"
 #include "llvm/Support/Casting.h"
 #include "llvm/Support/CommandLine.h"
 #include "llvm/Support/Debug.h"
 #include "llvm/Support/raw_ostream.h"
 #include "llvm/Transforms/Scalar.h"
#include<iostream>

using namespace llvm;
using namespace std;

namespace {

  class EnforcePass : public ModulePass {


    private:

      /*void instrument_one_trace(Module &M, IRBuilder<> &IRB, BasicBlock &BB, Instruction *last_instruction, uint32_t use_address,
        GlobalVariable *BranchTracePtr, 
        GlobalVariable *BranchTakenPtr, 
        GlobalVariable *BranchValue1Ptr,
        GlobalVariable *BranchValue2Ptr,
        GlobalVariable *BranchValueDoublePtr,
        GlobalVariable *BranchOperationPtr,
        GlobalVariable *New_Branch,
        GlobalVariable *ExtraParams
      );*/

      /*void instrument_one_coverage( 
        Module &M, IRBuilder<> &IRB, BasicBlock &BB, Instruction *last_instruction, uint32_t use_address, 
        GlobalVariable *AFLMapPtr,
        GlobalVariable *AFLPrevLoc,
        GlobalVariable *ExtraParams      
      );*/


    uint32_t inst_branches = 0;
    uint32_t inst_real_branches = 0;
    uint32_t inst_if_type = 0;
    uint32_t inst_switch_type = 0;


    public:

      static char ID;
      EnforcePass() : ModulePass(ID) { }
      bool runOnModule(Module &M) override;

  };
}
bool EnforcePass::runOnModule(Module &M){
	LLVMContext &C = M.getContext();
	std::string s;
	llvm::raw_string_ostream ss(s);

	IRBuilder<> IRB( C );
	for(auto &F:M){
		for(auto &BB:F){
			Instruction *term_inst = (dyn_cast<Instruction>(BB.getTerminator ()));
			ss<<*term_inst;
			std::cout<<ss.str()<<std::endl;
			//term_inst->print();
		}
	}
}

static void registerEnforcePassPass(const PassManagerBuilder &,
		                            legacy::PassManagerBase &PM) {

	  PM.add(new EnforcePass());

}


static RegisterStandardPasses RegisterEnforcePassPass(
		    PassManagerBuilder::EP_OptimizerLast, registerEnforcePassPass);

static RegisterStandardPasses RegisterEnforcePassPass0(
		    PassManagerBuilder::EP_EnabledOnOptLevel0, registerEnforcePassPass);
/*void instrument_one_trace(Module &M, IRBuilder<> &IRB, BasicBlock &BB, Instruction *last_instruction, uint32_t use_address,
        GlobalVariable *BranchTracePtr,
        GlobalVariable *BranchTakenPtr,
        GlobalVariable *BranchValue1Ptr,
        GlobalVariable *BranchValue2Ptr,
        GlobalVariable *BranchValueDoublePtr,
        GlobalVariable *BranchOperationPtr,
        GlobalVariable *New_Branch,
        GlobalVariable *ExtraParams
      ){
	LLVMContext &C = M.getContext();

}*/
