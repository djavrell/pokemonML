type pokemon = {
  id: int,
  name: string,
  baseExperiance: int,
  height: int,
};

module PokemonModel = {
  let pokemon = json: pokemon =>
    Json.Decode.{
      id: json |> field("id", int),
      name: json |> field("name", string),
      baseExperiance: json |> field("base_experience", int),
      height: json |> field("height", int),
    };
};
