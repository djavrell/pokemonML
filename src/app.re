open PokemonService;
open PokemonModel;

type state = {
  data: option(pokemon),
  value: string,
};

type action =
  | Loading
  | Loaded(pokemon)
  | UpdateValue(string)
  | KeyDown(int);

let component = ReasonReact.reducerComponent("App");

let initState = () => {data: None, value: ""};

let fetchData = ({ReasonReact.state, send}): unit => {
  pokemonFetcher(pokemonUrl(int_of_string(state.value)), data =>
    switch (data) {
    | Some(pokemon) => send(Loaded(pokemon))
    | None => send(Loading)
    }
  );
  send(Loading);
};

let reducer = (action, state) =>
  switch (action) {
  | Loading => ReasonReact.NoUpdate
  | Loaded(data) => ReasonReact.Update({...state, data: Some(data)})
  | UpdateValue(value) => ReasonReact.Update({...state, value})
  | KeyDown(13) => ReasonReact.SideEffects((self => fetchData(self)))
  | KeyDown(_) => ReasonReact.NoUpdate
  };

let make = _children => {
  ...component,
  initialState: initState,
  reducer,
  render: ({state, send}) =>
    <>
      <input
        value={state.value}
        onChange={event => send(UpdateValue(ReactEvent.Form.target(event)##value))}
        onKeyDown={event => send(KeyDown(ReactEvent.Keyboard.which(event)))}
      />
      <PokemonComponent pokemon=?{state.data} />
    </>,
};
