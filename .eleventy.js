
// The export statement makes these settings available to other files in 11ty
module.exports = function(eleventyConfig) {
  eleventyConfig.addPassthroughCopy("images");
  eleventyConfig.addPassthroughCopy("styles");

  eleventyConfig.addShortcode("picture", function(image, alt){
    return `<img src="/images/${image}" alt="${alt}" class="picture">`
  }
)


};