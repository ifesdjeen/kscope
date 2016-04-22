#pragma once

#include <string>
#include <vector>

#include "ASTNode.h"


class CallNode : public ASTNode {
public:
  std::string callee;
  std::unique_ptr<std::vector<std::unique_ptr<ASTNode> > > args;

  CallNode(const std::string &callee,
           std::unique_ptr<std::vector<std::unique_ptr<ASTNode> > > args)
    : callee(callee), args(std::move(args)) {};

  template<class Result> Result* render(Renderer<Result> *renderer) {
    renderer->render(this);
  }
};
