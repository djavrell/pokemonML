let compnent = ReasonReact.statelessComponent("Text")

let make = (~message, _children) => {
  ...compnent,
  render: _self =>
    <h3> (ReasonReact.string(message)) </h3>
};