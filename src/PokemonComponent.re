open PokemonModel;

let component = ReasonReact.statelessComponent("Pokemon");

let make = (~pokemon=?, _children) => {
  ...component,
  render: _self =>
    switch (pokemon) {
    | Some(pokemon) => <div> <Text message={pokemon.name} /> </div>
    | None => <Text message="loading..." />
    },
};
