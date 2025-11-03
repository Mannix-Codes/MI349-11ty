const data = require('./information.json');


function get_index(_title){
  const idx = data.titles.indexOf(_title);
  return idx;
}

function get_picture(img_index) {
  const image=data.images[img_index];
  const alt=data.alt[img_index];
  return `<img src="/images/${image}" alt="${alt}" class="picture">`
}
// The export statement makes these settings available to other files in 11ty
module.exports = function(eleventyConfig) {
  eleventyConfig.addPassthroughCopy("images");
  eleventyConfig.addPassthroughCopy("styles");

  eleventyConfig.addShortcode("index_pic", function(title){
    let _index = get_index(title);
    return get_picture(_index)
  }
  )
  eleventyConfig.addShortcode("index_text", function(title){
    let _index = get_index(title);
    let _text = data.text[_index];
    return `<p>${_text}</p>`
  }
  )

};