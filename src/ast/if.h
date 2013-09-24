#pragma once

#include "llvm/IR/Value.h"

#include "node.h"
#include "codegen/context.h"


class IfNode : public ASTNode {
  ASTNode *condition, *then, *_else;

public:
  IfNode(ASTNode *cond, ASTNode *then, ASTNode *_else);
  virtual llvm::Value *codegen(Context *context);
};